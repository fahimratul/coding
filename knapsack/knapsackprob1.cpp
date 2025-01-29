
#include<bits/stdc++.h>

using namespace std;

int fractional_knapsack(int n, int W, vector<int> &v, vector<double> &w){
    vector<pair<double, int>> ratio;
    for(int i=0; i<n; i++){
        ratio.push_back({(double)v[i]/(double)w[i], i});
    }
    sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());
    int ans=0;
    for(int i=0; i<n; i++){
        if(W>0){
            int pickitem=ratio[i].second;
            double x=min(1.0, W/w[pickitem]);
            //cout<<x<<endl;
            W=W-x*w[pickitem];
           // cout<<W<<endl;
            ans=ans+x*v[pickitem];
        }
    }
    return ans;
}

int main(){
    int n;
    double W;
    vector<double> w;
    vector<int> v;
    cout<<"Number of items"<<endl;
    cin>>n;
    cout<<"Capacity of knapsack"<<endl;
    cin>>W;
    cout<<"Enter the weights of items"<<endl;
    for(int i=0; i<n;i++){
        int l;
        cin>>l;
        w.push_back(l);
    }
    cout<<"Enter the values of items"<<endl;
    for(int i=0; i<n;i++){
        int l;
        cin>>l;
        v.push_back(l);
    }
    cout<<"Maximum value: ";
    cout<<fractional_knapsack(n, W, v, w)<<endl;
}