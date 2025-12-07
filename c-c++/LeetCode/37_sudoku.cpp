#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>>&board,int row,int col,int dig){
    //Horizontal
    for(int j=0;j<9;j++){
        if(board[row][j]==dig){
            return false;
        }
    }
    //Vertical
    for(int i=0;i<9;i++){
        if(board[i][col]==dig){
            return false;
        }
    }

    //grid

    int c1=(col/3)*3;
    int r1 = (row/3)*3;

    for(int i=r1;i<r1+3;i++){
        for(int j=c1;j<c1+3;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }


    return true;
    
    
}


bool helper(vector<vector<int>> &board,int row,int col){
    if(row==9){
        return true;
    }

    int nextRow=row,nextCol = col+1;
    if(nextCol == 9){
        nextCol = 0;
        nextRow = row+1;
    }
    if(board[row][col] != 0){
        return helper(board,nextRow,nextCol);
    }

    //Place Digit
    for(int dig=1;dig<=9;dig++){
        if(isSafe(board,row,col,dig)){
            board[row][col] = dig;
            if(helper(board,nextRow,nextCol)){
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(const vector<vector<int>>& board) {
    cout<<"--------------------"<<endl;
    for (int i = 0; i < 9; i++) {
        cout<<"|";
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "|"<<endl;
    }
    cout<<"--------------------";
}


int main(){
    vector<vector<int>> board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    cout << "Sudoku Before Solving:\n";
    printBoard(board);

    if (helper(board, 0, 0)) {
        cout << "\nSudoku After Solving:\n";
        printBoard(board);
    } else {
        cout << "No solution exists!";
    }



    return 0;
}