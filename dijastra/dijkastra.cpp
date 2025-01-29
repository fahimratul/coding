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

void dijkastra(int n, vector<pair<int, int>> graph[], int src=1, int dest=5){
    int key[n+1], par[n+1], visited[n+1];
    for(int i=1; i<=n; i++){
        key[i]=INT_MAX;
        par[i]=-1;
        visited[i]=0;
    }
    vector<int> path;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>  pq;

    key[src]=0;
    par[src]=-1;    
    pq.push({0, src});  
    path.push_back(src);
    while(!pq.empty()){
        int node=pq.top().second;
    
        pq.pop();
        visited[node]=1;
        int weight=key[node];
        for(auto it: graph[node]){
            int l=it.first;
            int o=it.second;
            if(key[o]>l+weight && visited[o]==0){
                key[o]=l+weight;
                par[o]=node;
                pq.push({key[o], o});
                path.push_back(o);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout<<"distance from "<<src<<" to "<<i<<" is: "<<key[i]<<endl;
    }
    cout<<"the path is: ";  
    for(auto i: path){
        cout<<i<< " ";
    }   
    cout<<endl;
    cout<<"the path from "<<src<<" to "<<dest<<" is: ";
    printpath(par, dest);
    cout<<endl;
     
    cout<< "total distance is: "<<key[dest]<<endl;
}




int main(){
    int n, e;
    cin>>n>>e;

    vector<pair<int, int>> graph[n+1];
    for(int i=0; i<e; i++){
        int w,u,v;
        cin>>v>>u>>w;
        cout<<v<<" to "<<u<<" with weight "<<w<<endl;
        graph[v].push_back({w,u});
    }
    dijkastra(n, graph);
}