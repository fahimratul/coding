#include<bits/stdc++.h>

using  namespace std;

void LCS(string s1, string s2){
    int n1=s1.size();
    int n2= s2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));
    for(int i =1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(s1[i-1]== s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    } 
    string ssc="";
    int i=n1, j=n2;
    while(i>=0 && j>=0){
        if(i>0 && j>0 && s1[i-1]==s2[j-1]){
            ssc=ssc+s1[i-1];
            i--;j--;
        }
        else if(j>0  && (i==0 || dp[i][j-1]>= dp[i-1][j])){
            ssc=ssc+s2[j-1];
            j--;
        }
        else{
            ssc=ssc+s1[i-1];
            i--;
        }
        cout<<ssc<<endl;

    }
    reverse(ssc.begin(), ssc.end());
    cout<<ssc<<endl;
}

int main(){
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    LCS(X, Y);
}