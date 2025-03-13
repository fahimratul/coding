#include<bits/stdc++.h> 
using namespace std;


void solve(vector<int> &v,vector<int> &subset,int index,int target,vector<vector<int>> &res){
    if(target==0){
        res.push_back(subset);
        return;
    }
    if(index==v.size()){
        return;
    }
    if(v[index]<=target){
        subset.push_back(v[index]);
        solve(v,subset,index,target-v[index],res);
        subset.pop_back();
    }
    solve(v,subset,index+1,target,res);

}


int main(){
    vector<int> v={2,3,5};
    int target=8;
    vector<vector<int>> res;    
    vector<int> subset;
    solve(v,subset,0,target,res);
    for(auto i:res){
        cout<<"[";
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"], ";
    }
}