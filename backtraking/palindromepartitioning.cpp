#include<bits/stdc++.h>

using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}


void solve(string s, int index, vector<string> &subset, vector<vector<string>> &res){
    if(index==s.size()){
        res.push_back(subset);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)){
            subset.push_back(s.substr(index,i-index+1));
            solve(s,i+1,subset,res);
            subset.pop_back();
        }
    }
}

int main(){
    string s="aab";
    vector<string> subset;
    vector<vector<string>> res;
    solve(s,0,subset,res);
    for(auto i:res){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"], ";
    }
}