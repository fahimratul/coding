#include<bits/stdc++.h>

using namespace std;

void printsubset(vector<int> &v,vector<int> &subset,int index, vector<vector<int>> &res){
    if(index == v.size()){
        res.push_back(subset);
            return;
    }

    //cout<<"pushing "<<v[index]<<endl;
    subset.push_back(v[index]);
    printsubset(v,subset,index+1,res);
    while(index+1<v.size() && v[index]==v[index+1]){
        index++;
    }
    //cout<<"popping "<<v[index]<<endl;
    subset.pop_back();
    printsubset(v,subset,index+1,res);
}


int main(){
    vector<int> v={2,1,2};
    sort(v.begin(),v.end());
    vector<int> subset;
    vector<vector<int>> res;
    printsubset(v,subset,0,res);
    for(auto i:res){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"], ";
    }
}