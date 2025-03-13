#include<bits/stdc++.h>

using namespace std;

#define V 6

bool BFS(int graph[V][V], int s, int t, int parent[]){
    bool visited[6];
    memset(visited,0,sizeof(visited));


    for(int i=0;i<6;i++){
        visited[i]=false;
    }
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<6;v++){
            if(visited[v]==false && graph[u][v]>0){
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return (visited[t]);
}



void minCut(int graph[V][V],int residualGraph[V][V], int source) {
    bool visited[V] = {false};
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    cout << "Minimum Cut Edges:" << endl;
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (visited[u] && !visited[v] && graph[u][v]) {
                cout << u << " -> " << v << endl;
            }
        }
    }
}


int FordFulkerson(int graph[V][V], int s, int t){
    int u,v;
    int rGraph[V][V];
    for(u=0;u<V;u++){
        for(v=0;v<V;v++){
            rGraph[u][v]=graph[u][v];
        }
    }
    int parent[V];

    int max_flow=0;
    
    while(BFS(rGraph,s,t,parent)){
        int path_flow=INT_MAX;

        for(v=t; v!=s; v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,rGraph[u][v]);
        }
        cout<<path_flow<<endl;
        cout<<endl;
        for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
        for(int i=0;i<6;i++){
            for(int j=0;j<6;j++){
                cout<<rGraph[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    minCut(graph,rGraph,0);
    return max_flow;
}







int main(){
    int graph[V][V]={{0,16,13,0,0,0},
                     {0,0,10,12,0,0},
                     {0,4,0,0,14,0},
                     {0,0,9,0,0,20},
                     {0,0,0,7,0,4},
                     {0,0,0,0,0,0}};

    cout<<"The maximum possible flow is: "<<FordFulkerson(graph,0,5)<<endl;

    cout<<endl;
}