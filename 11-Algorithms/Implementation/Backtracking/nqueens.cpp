#include<bits/stdc++.h>
using namespace std;
const int n = 4;

void printSolutions(int board[n][n]){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
}


bool isSafe(int board[n][n], int row, int col){

  for(int i = 0; i < col; i++){
    if(board[row][i])
    return false;
  }

  for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
    if(board[i][j])
    return false;
  }

  for(int i = row, j = col; j >= 0 && i < n; j--, i++){
    if(board[i][j]) return false;
  }

  return true;
}

bool nqueens(int board[n][n], int col){
  if(col >= n){
    return true;
  }

  for(int i = 0; i < n; i++){
    if(isSafe(board, i, col)){
      board[i][col] = 1;

      if(nqueens(board, col+1)){
        return true;
      }
      board[i][col] = 0;
    }
  }
  return false;
}

void solve(){

  int board[n][n] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

  if(!nqueens(board, 0)){
    cout<<"No solutions possible"<<endl;
    return;
  }
  printSolutions(board);
  return;
}



int main(){

  solve();
  return 0;

}
