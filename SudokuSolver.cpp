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

bool isSafe(int arr[9][9],int currRow,int currCol,int num){
  int row = currRow - currRow%3;
  int col = currCol - currCol%3;
  for(int i=0;i<9;i++){
    if(arr[currRow][i]==num){
      return false;
    }
  }
  for(int i=0;i<9;i++){
    if(arr[i][currCol]==num){
      return false;
    }
  }
  for(int i=row;i<row+3;i++){
    for(int j=col;j<col+3;j++){
      if(arr[i][j]==num){
        return false;
      }
    }
  }
  return true;
}

bool solve(int arr[9][9]){
  bool emptyLeft = true; // Assuming at beginning there are empty boxes
  int row = -1; 
  int col = -1;
  
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      if(arr[i][j] == 0){
        // we found empty location
        row = i; // assining locati
        col = j;
        emptyLeft = false;
        break;
      }
    }
    if(emptyLeft == false){
      break;
    }
  }

  if(emptyLeft){
    return true;
  }

  for(int i=1;i<=9;i++){
    if(isSafe(arr, row, col, i)){
      arr[row][col] = i;
      if(solve(arr)){
        return true;
      }
      else{
        arr[row][col] = 0;
      }
    }
  }
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