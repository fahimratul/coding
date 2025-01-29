#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];


void printitems(vector<int> &v, vector<int> &w, int n){
    for(int i=0; i<n; i++){
        cout<<"Value of item "<<i+1<<" is:"<<v[i]<<" Weight is: "<<w[i]<<endl;
    }
}


// bool comp(item a, item b ){
//     return a.ratio>b.ratio;
// }

float fractionalkansack(int n, int W,vector<int> &v, vector<int> &w){
 

    printitems(v,w,n);
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
    cin>>items_no>>capacity;
    vector<int> v;
    vector<int> w;
    for(int i=0; i<items_no; i++){
        int l, j;
        cin>>l>>j;
        v.push_back(l);
        w.push_back(j);    
    }
    cout<<fractionalkansack(items_no, capacity,v, w)<<endl;
}
