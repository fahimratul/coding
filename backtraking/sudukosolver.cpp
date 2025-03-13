#include<bits/stdc++.h> 
using namespace std;

bool isvalid(vector<vector<char>> &suduko, int row, int col, char num){
    for(int i=0;i<9;i++){
        if(suduko[row][i] == num || suduko[i][col] == num){
            return false;
        }
    }
    int startrow = row - row%3;
    int startcol = col - col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(suduko[i + startrow][j + startcol] == num){
                return false;
            }
        }
    }
    return true;
}



bool solve(vector<vector<char>> &suduko){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(suduko[i][j] == '.'){
                for(char num = '1'; num <= '9'; num++){
                    if(isvalid(suduko, i, j, num)){
                        suduko[i][j] = num;
                        if(solve(suduko)){
                            return true;
                        }
                        suduko[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    vector<vector<char>> suduko = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solve(suduko);
    for(auto i:suduko){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}