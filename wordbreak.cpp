#include<bits/stdc++.h>

using namespace std;

#define count 26
struct Node{
    Node *child[26];
    int EOW;
};


Node* root;


Node *createnode(){
    Node *n= new Node;
    n->EOW=0;
    for (int i = 0; i <count; i++)
    {
        n->child[i]=nullptr;
    }
    return n;
}


void insert(string s){
    Node *u= root;
    for (int  i = 0; i <s.size(); i++)
    {
        char c=s[i];
        int l= c-'a';
        if(u->child[l]==nullptr){
            u->child[l]=createnode();
        }
        u= u->child[l];
    }
    u->EOW=1;
}


void printtree(Node *cur=root, string s=""){
    if(cur->EOW==1){
        cout<<s<<endl;
    }
    for (int i = 0; i < count; i++)
    {
        if(cur->child[i]==nullptr){
            continue;
        }
        char ch=i+'a';
        printtree(cur->child[i], s+ch);
    }
    
}

bool find(string s){
    Node *cur=root;
    for (int i = 0; i <s.size(); i++)
    {
        int j =s[i]-'a';
        if(cur->child[j]==nullptr){
            return false;
        }
        cur = cur->child[j];
    }
    return cur->EOW;
}

bool isleaf(Node *cur){
    bool ret=true;
    for (int i = 0; i < count; i++)
    {
        if(cur->child[i]!=nullptr){
            ret=false;
        }
    }
    return ret;
}


bool isjunction(Node * cur){
    if(cur->EOW==1){
        return true;
    }
    if(isleaf(cur)){
        return false;
    }
    return true;
}

void removeEdge(Node* u, char c, int d){
    if(d==0){
        return;
    }
    int j=c-'a';
    Node *v= u->child[j];
    u->child[j]=nullptr;
    free(v);
}

int deletenode(string s, Node *cur=root, int i =0){
    if(cur==nullptr){
        return 0;
    }
    if(i=s.size()){
        if(cur->EOW==0){
            return 0;
        }
        if(isleaf(cur)==false){
            cur->EOW=0;
            return 0;
        }
        return 1;
    }
    int j=s[i]-'a';
    int d=deletenode(s, cur->child[j], i+1);
    removeEdge(cur, s[i], d);
    if(isjunction(cur)){
        d=0;
    }
    return d;
}


bool helper(string key, vector<string> &s){
    if(key.size()==0){
        return true;
    }
    for(int i=0; i<key.size(); i++){
        string first= key.substr(0, i+1);
        string second= key.substr(i+1);
        cout<<first<<" "<<second<<endl;
        if(find(first)==1 && helper(second, s)){
            s.push_back(first);
            return true;
        }

    }
    return false;
}








int main(){
    root = createnode();

    vector<string> dict={"i", "like", "sum", "sumsung", "a", "mobile"};
    for(int i=0; i<dict.size(); i++){
        insert(dict[i]);
    }
    

    printtree();
    string key= "ilikesums";
    vector<string> s;
    cout<<helper(key, s)<<endl;;
    for(int i=s.size()-1; i>=0; i--){
        cout<<s[i]<<" ";
    }
    
    free(root);

    return 0;
}

