#include<bits/stdc++.h>

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};



int maximumabsolutedifference(vector<vector<int>> heights){
    int row=heights.size();
    int col=heights[0].size();
    vector<vector<int>> minDiff(row, vector<int>(col, INT_MAX));
    vector<vector<int>> visited(row, vector<int>(col, 0));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int, int>>>>  pq;
    pq.push({0,{0,0}});
    visited[0][0]=1;
    while(!pq.empty()){
        pair<int,pair<int,int>> index=pq.top();
        pq.pop();
        int curRow=index.second.first;
        int curCol=index.second.second;
        int minDiffValue=index.first;
        for(int i=0; i<4; i++){
            int newrow=curRow+dx[i];
            int newcol=curCol+dy[i];
            if(newrow>=0 && newrow<row && newcol>=0 && newcol<col){
               int diff=abs(heights[curRow][curCol]-heights[newrow][newcol]);
                if (minDiff[newrow][newcol]>diff){ 
                    minDiff[newrow][newcol] = diff;
                    cout << newrow << " " << newcol << " " << minDiff[newrow][newcol] << endl;
                    pq.push({minDiff[newrow][newcol], {newrow, newcol}});
                    visited[newrow][newcol] = 1;
            }
        }
    }
}
    return minDiff[row-1][col-1];   

}

int main(){
    vector<vector<int>> heights;
    heights = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout<<maximumabsolutedifference(heights);    
}