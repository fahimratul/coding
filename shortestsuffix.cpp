#include<bits/stdc++.h>

using namespace std;

struct Node{
    int EoW;
    Node* children[26]; 
    int freq;
};

Node* root;

Node* createNode()
{
    Node* n= new Node;
    n->EoW=0;
    n->freq=-1;
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
            u->children[i]->freq=1; 
        }
        else{
            u->children[i]->freq++;
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
      //  cout<<ch<<" "<<cur->children[i]->freq<<endl;
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
    return true;
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

void getprifix(string key, vector<string> &ans){
    Node *temp=root;
    string prefix="";
    for (int i = 0; i < key.size(); i++)
    {
        prefix=prefix+key[i];
        int j=key[i]-'a';
        if(temp->children[j]->freq==1){
            ans.push_back(prefix);
            return;
        }
        temp=temp->children[j];
    }
    
}


int main(){
    root = createNode();
    vector<string> dictonary={ "zebra", "dog", "dove", "duck" };


    for (int i = 0; i < dictonary.size(); i++)
    {
        insert(dictonary[i]);
    }
    printTRIE();
    vector<string> ans;
    for (int i = 0; i < dictonary.size(); i++)
    {
        getprifix(dictonary[i], ans);
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    cout<<find("zeba")<<endl;
}
