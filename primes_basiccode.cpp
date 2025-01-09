#include<bits/stdc++.h>

using namespace std;



int main(){
    int n, e;
    cin>>n>>e;
    vector<pair<int, int>> graph[n];
    for(int i=0; i<e; i++){
        int w,u,v;
        cin>>v>>u>>w;
        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }
    
    int key[n], par[n], mst[n];
     for(int i=0; i<n; i++){
        key[i]=INT_MAX;
        par[i]=-1;
        mst[i]=0;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>  pq;

    key[0]=0;

    par[0]=-1;
    pq.push({0, 0});


    while(!pq.empty()){
        int temp= pq.top().second;
        pq.pop();
        mst[temp]=1;

        for(auto it: graph[temp]){
            int l=it.first;
            int o=it.second;
            if(key[o]>l && mst[o]==0){
               key[o]=l;
               par[o]=temp;
                pq.push({key[o], o} );
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<key[i]<< " ";
    }
    cout<<endl;
        int cost=0; 
        for(int i=0; i<n; i++){
            cost+=key[i];
        }

        cout<<cost<<endl;

}
