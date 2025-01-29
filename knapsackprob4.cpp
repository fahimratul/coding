#include<bits/stdc++.h>

using namespace std;

int maxweight(int n, int W, vector<int> &v, vector<int> &w){
    int dp[W+1]={0};
    for(int j=0; j<=W; j++){
        for(int i=0; i<n; i++){
            if(w[i]<=j){
                dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
            }
    }
    }
    return dp[W];
}

int main(){
    int items_no, capacity;
    cout<<"Number of items:";
    cin>>items_no;
    cout<<"Capacity of knapsack:";
    cin>>capacity;
    vector<int> v;
    vector<int> w;
    cout<<"Weight:";
    for(int i=0; i<items_no; i++){
        int l;
        cin>>l;
        w.push_back(l);    
    }
    cout<<"Value:";
    for(int i=0; i<items_no; i++){
        int l;
        cin>>l;
        v.push_back(l);
    }
    cout<<"Maximum value: ";
    cout<<maxweight(items_no, capacity,v, w)<<endl;
}