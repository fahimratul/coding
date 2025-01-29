#include<bits/stdc++.h>

using namespace std;

void printpath(vector<int> &par, int n){
    if(par[n]==-1){
        cout<<n<<" ";
        return;
    }
        printpath(par, par[n]);
        cout<<n<<" ";
}



int cheapestFlight(int n, vector<vector<pair<int, int>>> &flights, int dst, int src, int k){
    vector<int> key(n+1, INT_MAX), par(n+1, -1), visited(n+1, 0);
    int post;

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    key[src]=0;
    par[src]=-1;
    post=-1;
    pq.push({0,src});
    while(!pq.empty()){
        int node= pq.top().second;
        pq.pop();
        visited[node]=1;
        int weight=key[node];
        post++;
        for(auto it: flights[node]){
            int cost=it.first;
            int child=it.second;
            if(key[child]>weight+cost && post<=k){
                key[child]=weight+cost;
               // cout<<key[child]<<endl;
                par[child]=node;
                pq.push({key[child], child});
            }
        }
    }
    
    printpath(par, dst);
    if(key[dst]!=INT_MAX){
        return key[dst];
    }
    else{
        return -1;
    }
}



int main(){
    int n, e;
    cin>>n>>e;
    vector<vector<pair<int, int>>> flights(n);
    for(int i=0; i<e; i++){
        int u, v, w;
        cin>>u>>v>>w;
        flights[u].push_back({w, v});
    }

    int src, dst, k;
    cin>>src>>dst>>k;
    //cout<<"value:";
    cout<<cheapestFlight(n, flights, dst, src, k)<<endl;
}