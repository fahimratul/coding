#include<bits/stdc++.h>

using namespace std;


void printlcs(string s1,string s2,vector<vector<int>> dp,int i, int j){
   int n=i;
   int m=j;
   string ans="";
   while(n!=0 && m!=0){
    if(s1[n-1]==s2[m-1]){
        ans+=s1[n-1];
        n--;
        m--;
    }
    else if(dp[n][m-1]>dp[n-1][m]){
        m--;
    }
    else{
        n--;
    }
   }
   reverse(ans.begin(), ans.end());
   cout<<ans<<endl;
}


int LCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // for(int i=0; i<=m; i++){
    //     for(int j=0; j<=n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    printlcs(s1,s2,dp,m,n);   
    return dp[m][n];
}



// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     LCS(s1,s2);
//     return 0;
// }