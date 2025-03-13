#include <bits/stdc++.h>
using namespace std;
#define granite_state ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define line cout << "\n"
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define vsb (v).begin(),(v).end()
#define vse (v).rbegin(),(v).rend()
#define spc " "
#define pb push_back
#define pf push_front;


void print_optimal_parens(vector<vector<int>> &s, int i, int j) 
{
    if (i == j) 
    {
        cout << "A" << i;
        return;
    }
    cout << "(";
   // cout<<i<<" "<<j<<endl;
    //cout<<i<<" "<<s[i][j]<<endl;
    print_optimal_parens(s, i, s[i][j]);
    //cout<<i<<" "<<s[i][j]<<endl;
    print_optimal_parens(s, s[i][j] + 1, j);
    cout << ")";
}
int mcm_rec(vector<int>arr,int i,int j)
{
    if(i==j) return 0;
    int ans = INT_MAX;
    for(int k=i;k<j;k++)
    {
         int cost1 = mcm_rec(arr,i,k);
         int cost2 = mcm_rec(arr,k+1,j);
         int cur_cost = cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
         ans = min(ans,cur_cost);
    }
    return ans;
}

int mcm_mem(vector<int>arr,int i,int j,vector<vector<int>>&dp)
{
    if(i==j) return dp[i][j] = 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = INT_MAX;
    //dp[i][j] = INT_MAX;
    for(int k=i;k<j;k++)
    {
         int cost1 = mcm_mem(arr,i,k,dp);
         int cost2 = mcm_mem(arr,k+1,j,dp);
         int cur_cost = cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
         ans = min(ans,cur_cost);
         //dp[i][j] = min(dp[i][j],cur_cost);
    }
    return dp[i][j] = ans;
    //return dp[i][j];
}

int mcm_tab(vector<int>arr,vector<vector<int>>&s)
{
     int n = arr.size();
     vector<vector<int>>dp(n,vector<int>(n,0));
     for(int len=2;len<n;len++)
     {
         for(int i=1;i<=n-len;i++)
         {
              int j = i+len-1;
              dp[i][j] = INT_MAX;
              for(int k=i;k<j;k++)
              {
                  int cost1 = dp[i][k];
                  int cost2 = dp[k+1][j];
                  int cur_cost = cost1+cost2+(arr[i-1]*arr[k]*arr[j]);
                  if (cur_cost < dp[i][j]) 
                  {
                     dp[i][j] = cur_cost;
                     s[i][j] = k;
                  }
              }
         }
     }
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
        cout<<s[i][j]<<" ";
       line;
     }
     print_optimal_parens(s,1,n-1);
     line;
     return dp[1][n-1];
}
signed main()
 {
    granite_state
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    vector<vector<int>>dp(n,vector<int>(n,-1));
    vector<vector<int>>s(n,vector<int>(n,-1));
    cout<<mcm_mem(arr,1,n-1,dp)<<endl;
    cout<<mcm_rec(arr,1,n-1)<<endl;
    cout<<mcm_tab(arr,s)<<endl;
}

    ////////////////////////////////////////////////////
    //                                                 //
    //                 A                               //
    //                                                 //
    //                 L                               //
    //                                                 //
    //                 I                               //
    //                                                 //
    //                 F                               //
    /////////////////////////////////////////////////////
//think simply, it's always easier than it seems at first
    //PEN AND PAPER instead of ms paint
    //keep at it even if it feels exhausting(we're not doing this for fun anymore)
    //2 GHONTAR AGER EDITORIAL DHORBI NA