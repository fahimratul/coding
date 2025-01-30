#include<bits/stdc++.h>

using namespace std;    

void printpath(int par[], int n){
    if(par[n]==-1){
        cout<<n<<" ";
        return;
    }
    printpath(par, par[n]);
    cout<<n<<" ";
}


void bellman(int n, vector<pair<pair<int, int>, int>> edges, int src=1, int dest=5){
    int key[n+1], par[n+1];
    for(int i=0; i<=n; i++){
        key[i]=INT_MAX;
        par[i]=-1;
    }

    key[src]=0;

    par[src]=-1;
    for(int i =0 ; i<n-1; i++){
        for(auto it: edges){
            int u=it.first.first;
            int v=it.first.second;
            int w=it.second;
            if(key[u]+w<key[v]){
                key[v]=key[u]+w;
                par[v]=u;
            }
        }
    }
    for(auto it: edges){
        int u=it.first.first;
        int v=it.first.second;
        int w=it.second;
        if(key[u]+w<key[v]){
            cout<<"No Solution of this graph" <<endl;
            return;
        }
    }


    for(int i=1; i<n+1; i++){
        cout<<i<<"->"<<key[i]<<endl;
    }
    cout<<endl;
    cout<<"the path from "<<src<<" to "<<dest<<" is: ";
    printpath(par, dest);
    cout<<endl;
}



int main(){
    int n, e;
    cin>>n>>e;

    vector<pair<pair<int,int>, int>> edges;
    for(int i=0; i<e; i++){
        int w,u,v;
        cin>>u>>v>>w;
        edges.push_back({{u, v}, w});
    }
    // for(auto i: edges){
    //     cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
    // }
    bellman(n, edges);
}