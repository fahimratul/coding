#include<bits/stdc++.h> 

using namespace std;

int dp[1000][1000];

float fractionalkansack(int n, int W,vector<int> &v, vector<int> &w){

    for(int i=0; i<n; i++){
        dp[0][i]=0;
    }
    for(int i=0; i<=W; i++){
        dp[i][0]=0;
    }
    for(int i=1;i<=n; i++){
        for(int j=1; j<=W; j++){
            if(w[i-1]<=j){
                dp[i][j]=max(v[i-1 ]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][W];
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
    cout<<fractionalkansack(items_no, capacity,v, w)<<endl;
}