#include<bits/stdc++.h>

using namespace std;

int dp[1000];

int main(){
    int n, amount;
    //cout<<"Number of coins:";
    cin>>n;
    //cout<<"Amount:";
    cin>>amount;
    cout<<amount<<endl;
    vector<int> coins;
    //cout<<"Coins:";
    for(int i=0; i<n; i++){
        int l;
        cin>>l;
        coins.push_back(l);
    }
    dp[0]=1;

    for(int i=1; i<=amount; i++){
        dp[i]=0;
        for(int it=0; it<n; it++){
            if(i>=coins[it]){
                //cout<<i<<" "<<coins[it]<<" ";
                //cout<<dp[i-coins[it]]<<" ";
                dp[i]=dp[i]|dp[i-coins[it]];
                //cout<<dp[i]<<endl;
            }
        }
    }
    for(int i=0; i<=amount; i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i=0; i<=amount; i++){
        cout<<dp[i]<<" ";
    }
    
}