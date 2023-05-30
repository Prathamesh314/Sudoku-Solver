#include<bits/stdc++.h>
using namespace std;


int arr[9][9] = {
    {6,0,3,5,0,0,8,0,0},
    {0,0,0,4,0,9,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {8,0,0,0,6,0,0,2,0},
    {0,0,0,9,0,7,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,7,0,6,0,0},
    {5,9,0,0,0,0,0,0,0},
    {0,4,0,0,0,0,0,0,7}
};

// Created a visually appealing sudoku board
void printBoard(int arr[9][9]){

    for(int i=0;i<9;i++)
    {
        printf("|---|---|---|---|---|---|---|---|---|\n");
        for(int j=0;j<9;j++){
            printf("| %d ",arr[i][j]);
        }
        printf("|\n");
        
    }
  printf("|---|---|---|---|---|---|---|---|---|\n");

}

// Checking whether the given position is safe for given number or not
bool isSafe(int arr[9][9],int currRow,int currCol,int num){
  int row = currRow - currRow%3; // Fetching starting row position of 3x3 box
  int col = currCol - currCol%3; // Fetching starting column position of 3x3 box
  for(int i=0;i<9;i++){ // Checking whether the given number is already present or not in particular row
    if(arr[currRow][i]==num){
      return false;
    }
  }
  for(int i=0;i<9;i++){ // Checking whether the given number is already present or not in a particular Columns
    if(arr[i][currCol]==num){
      return false;
    }
  }
  for(int i=row;i<row+3;i++){ // Checking whether the given number is already present or not in 3x3 box
    for(int j=col;j<col+3;j++){
      if(arr[i][j]==num){
        return false;
      }
    }
  }
  // If all the above statements are false that means we got correct position for given number
  return true;
}


// We try to solve the sudoku here
bool solve(int arr[9][9]){
  bool emptyLeft = true; // Assuming at beginning there are empty boxes
  int row = -1; 
  int col = -1;
  
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(arr[i][j] == 0){
        // we found empty location
        row = i; // assining empty row location
        col = j; //  assigning empty column location
        emptyLeft = false; // If we get an empty location that means sudoku is not yet solved and we return false
        break;
      }
    }
    if(emptyLeft == false){
      break;
    }
  }


  // If all the empty positions are finished that means sudoku is solved and we return true
  if(emptyLeft){
    return true;
  }

  // We try every number from 1 to 9 at empty position
  for(int i=1;i<=9;i++){
    if(isSafe(arr, row, col, i)){
      arr[row][col] = i; // This is our assumption of a number at that position
      if(solve(arr)){
        return true; // If above assumption is correct our sudoku will be solved and we return true
      }

      // Backtracking
      else{
        arr[row][col] = 0; // If our above assumption is false then that number is not at correct position so we will backtrack and try for another number
      }
    }
  }

  // If above all cases are not able to fill all the empty spaces that means sudoku is unsolvable and we return false
  return false;
}

int main()
{
    
    printBoard(arr);
    printf("\n\n");
    if(solve(arr)){
      printBoard(arr);
    }
    else{
      cout<<"Cannot Solve"<<endl;
    }

    return 0;
}