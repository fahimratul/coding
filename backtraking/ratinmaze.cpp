#include<bits/stdc++.h>

using namespace std;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
char dir[]={'U','R','D','L'};

vector<char> getpath(vector<vector<int>> &maze, int x, int y, int n, int m){
    if(x==n-1 && y==m-1){
        vector<char> v;
        return v;
    }
    for(int i=0;i<4;i++){
        int newx = x+dx[i];
        int newy = y+dy[i];
        if(newx>=0 && newx<n && newy>=0 && newy<m && maze[newx][newy]==1){
            maze[newx][newy]=2;
            vector<char> v = getpath(maze,newx,newy,n,m);
            if(v.size()!=0){
                v.push_back(dir[i]);
                return v;
            }
            maze[newx][newy]=1;
        }
    }
    vector<char> v;
    return v;
}


int main(){
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };


    vector<char> v = getpath(maze,0,0,4,4);
    for(auto i:v){
        cout<<i<<" ";
    }
}