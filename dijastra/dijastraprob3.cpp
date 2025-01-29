#include<bits/stdc++.h>

using namespace std;

int dx[]={-1,1,0,0,1,-1,-1,1};
int dy[]={0,0,-1,1,1,-1,1,-1};

int calculateshortestpash(vector<vector<int>> graph){
    int row=graph.size();
    int col=graph[0].size();
    if(graph[0][0]==1 || graph[row-1][col-1]==1){
        return -1;
    }

    vector<vector<int>> count(row, vector<int>(col, INT_MAX));

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
    pq.push({1,{0,0}});
    count[0][0]=1;
    while(!pq.empty()){
        pair<int,pair<int,int>> index=pq.top();
        pq.pop();
        int curRow=index.second.first;
        int curCol=index.second.second;
        int curCount=index.first;
        for(int i=0; i<8; i++){
            int nwRow=curRow+dx[i];
            int nwCol=curCol+dy[i];
            if(nwRow>=0 && nwRow<row && nwCol>=0 && nwCol<col){
                if(graph[nwRow][nwCol]==0){
                    if(count[nwRow][nwCol]>curCount+1){
                        count[nwRow][nwCol]=curCount+1;
                        pq.push({count[nwRow][nwCol], {nwRow, nwCol}});
                    }
                }
            }
        }
    }
    if(count[row-1][col-1]==INT_MAX){
        return -1;
    }
    return count[row-1][col-1];
}


int main(){
    vector<vector<int>> graph= {{0,1},{1,0}};
    cout<<calculateshortestpash(graph);
}