#include<bits/stdc++.h>

using namespace std;

bool isvalid(vector<string> &board,int row,int col){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q'){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    for(int i=row,j=col;i>=0 && j<board.size();i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
}


void printboard(vector<string> &board){
    for(auto i:board){
        cout<<i<<endl;
    }
    cout<<endl;
}


void nqueen(int row,vector<string> &board){
    if(row==board.size()){
        printboard(board);
        return;
    }
    for(int col=0;col<board.size();col++){
        if(isvalid(board,row,col)){
            board[row][col]='Q';
            nqueen(row+1,board);
            board[row][col]='-';
        }
    }
}



int main(){
    int n = 4; // You can change this to any size of the board
    vector<string> board(n, string(n, '-'));
    nqueen(0,board);
    
}