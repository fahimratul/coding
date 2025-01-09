#include<bits/stdc++.h>

using namespace std;

struct Node{
    int EoW;
    Node* children[26]; 
};

Node* root;

Node* createNode()
{
    Node* n= new Node;
    n->EoW=0;
    for(int i=0; i<26; i++){
        n->children[i]=nullptr;
    }
    return n;
}

void insert(string s){
    Node* u=root;
    for(int k=0; k<s.size(); k++){
        char c=s[k];
        int i = s[k]-'a';
        if(u->children[i]==nullptr){
            u->children[i]=createNode();
        }
        u=u->children[i];
    }
    u->EoW=1;
}

void printTRIE(Node* cur=root,string s=""){
    if(cur->EoW==1){
        cout<<s<<endl;
    }
    for(int i=0; i<26 ; i++){
        if(cur->children[i]==nullptr){
            continue;
        }
        char ch= i+'a';
        printTRIE(cur->children[i], s+ch);
    }
}


bool find(string s){
    Node* cur=root;
    for(int i=0; i<s.size(); i++){
        int j= s[i]-'a';
        if(cur->children[j]==nullptr){
            return false;
        }
        cur=cur->children[j];
    }
    return cur->EoW;
}

bool isLeaf(Node* cur)
{
    bool ret=true;
    for(int i=0; i<26; i++){
        if(cur->children[i]!=nullptr){
            ret=false;
        }
    }
    return ret;
}

bool isJunction(Node* cur) /// true means stop deleting
{
    if(cur->EoW==1){
        return true;
    }
    if(isLeaf(cur)){
        return false;
    }
    return true;
}

void removeEdge(Node *u, char c, int d){
    if(d==0){
        return;
    }
    int j=c-'a';
    Node* v=u->children[j];
    u->children[j]=nullptr;
    free(v);


}

int deleteNode(string s,Node* cur=root,int i=0)
{
    if(cur==nullptr){
        return 0;
    }
    if(i==s.size()){
        if(cur->EoW==0){
            return 0;
        }
        if(isLeaf(cur)==false){
            cur->EoW=0;
            return 0;
        }
        return 1;
    }
    int j = s[i]-'a';
    int d= deleteNode(s, cur->children[j], i+1);
    removeEdge(cur, s[i], d);
    if(isJunction(cur)){
        d=0;
    }
    return d;
}


int main(){
    root = createNode();

    insert("mist");
    insert("bubt");
    insert("buet");
    insert("mit");
    insert("mi");
    insert("cu");
    insert("exam");
    insert("exit");

    printTRIE();

    //cout << "mi " << find("mi") << endl;
    //cout << "mit " << find("mit") << endl;
    cout << "mist " << find("mist") << endl;
    //cout << "mis " << find("mis") << endl;
    //cout << "cuet " << find("cuet") << endl;

    deleteNode("mist");
    cout << "mist " << find("mist") << endl;

    printTRIE();

    free(root);

    return 0;
}
