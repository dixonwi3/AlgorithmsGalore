/*
Description
Dr. Xenovian has come up with an even better layout for the cores in her new computer system. This time, though, her specialized architecture requires that the cores are divided into two processing units, a CPU and an IPU (intelligence processing unit), each of which must be arranged in a PLUS shape. These pluse-shaped processing units have to be placed to avoid the other components on the motherboard. Can you help her figure out how big to make them?

You are given a grid of size N-by-M representing the motherboard. Each cell on this grid is either a good or bad place to put a core.

Each processing unit must be shaped like a plus sign on a grid. A valid plus has a horizontal line of cells and a vertical line of cells of equal lengths and crossing in the middle.

The overall processing speed is the number of cells in the CPU times the number of cells in the IPU. You must calculate the maximum processing speed.

Input Format

The first line contains two space-separated integers, N and M.

The N subsequent lines each contain M characters, where each character is either G (a good place to put a core) or B (a bad place to put a core).

 Constraints

2 ≤ N ≤ 15
2 ≤ M ≤ 15
Output Format

 Output the maximum production level.
*/

#include <iostream>
#include <vector>
using namespace std;
int checkPlus(int r, int c, int n, int m, int **board){
  int checkLength = 0;
  int length = 0;
  while(true){
    int u = r - checkLength;
    int d = r + checkLength;
    int l = c - checkLength;
    int ri = c + checkLength;
    // Check to make sure these cells are in bounds and middle one is 1
    //cout << "Pre if statement: " << board[r][c] << endl;
    if (board[r][c] == 1 or board[r][c] == 2){
      //cout << "Past if statement: " << board[r][c] << endl; 
      //cout << "checkLength: " << checkLength << endl;
      board[r][c] = 2;
      // if we're in bounds
      if (u < n && u >= 0 
      && d < n && d >=0 && l < m && l >=0
      && ri < m && ri >=0){
        //cout << "we're in bounds" << endl;
        // if all surrounding cells are a 1
        //cout << board[u][c] << board[d][c] << board[r][l] << board[r][ri]<< endl;
        if ((board[u][c] == 1 && board[d][c] == 1 && board[r][l] == 1 && board[r][ri] == 1) ||
        checkLength == 0 ){
          //cout << "incrementing" << endl;
          board[u][c] = 2;
          board[d][c] = 2;
          board[r][l] = 2;
          board[r][ri] = 2;
          // increment length
          if (checkLength == 0){
            checkLength++;
          }
          else{
            checkLength++;
            length++;
          }
        }
        else{
          return (length * 4) + 1;
        }
      }
      else{
        return (length * 4) + 1;
      }
    }
    else{
      return 0;
    }
  }
  return (length * 4) + 1;
}

int checkPlusNoChange(int r, int c, int n, int m, int **board){
  bool lengthIncrease = true;
  int checkLength = 0;
  int length = 0;
  while(lengthIncrease){
    int u = r - checkLength;
    int d = r + checkLength;
    int l = c - checkLength;
    int ri = c + checkLength;
    // Check to make sure these cells are in bounds and middle one is 1
    if (board[r][c] == 1){
      if (u < n && u >= 0 
      && d < n && d >=0 && l < m && l >=0
      && ri < m && ri >=0){
       // cout << u << " " << d << " " << l << " " << ri << endl;
        //cout<< "Passed the bounds" << endl;
        // if all surrounding cells are a 1
        if ((board[u][c] == 1 && board[d][c] == 1 && board[r][l] == 1 && board[r][ri] == 1) || checkLength == 0){
          // increment length
          if (checkLength == 0){
            checkLength++;
          }
          else{
            checkLength++;
            length++;
          }
        }
        else{
          return ((length) * 4) + 1;
        }
      }
      else{
        return ((length) * 4) + 1;
      }
    }
    else{
      return 0;
    }
  }
  return ((length) * 4) + 1;
}

int main(){
  int n;
  int m;
  string line;
  cin >> n;
  cin >> m;
  char c;
  int **board=new int*[n];

	//pointer initialization
	for(int i=0;i<n;i++)
	{
		board[i]=new int[m];
	}
  // occupy the board
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> c;
      if (c == 'G'){
        board[i][j] = 1;
      }
      else if (c == 'B'){
        board[i][j] = 0;
      }
    }
  }
  int length = 1;
  int maxSize = 0;
  int size = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      size = checkPlus(i, j, n, m, board);
      // cout << "Size 1: #" << (i*m) + j << endl;
      // cout << size << endl;
      // check to see if we have a plus, and what size it is
      // if we have a plus,
     if(size > 0){
       // check for another plus of biggest size
       int size2 = 0;
       int tempSize2 = 0;
        for (int r = 0; r < n; r++){
          for (int c = 0; c < m; c++){
            size2 = checkPlusNoChange(r, c, n, m, board);
           // cout << "Size 2 # "<< (r*m) + c << endl;
           // cout << tempSize2<< endl;
            if ((size * size2)> maxSize){
              maxSize = size2 * size;
            }
          }
        }
      }
      for (int r = 0; r < n; r++){
        for (int c = 0; c < m; c++){
          if (board[r][c] == 2){
              board[r][c] = 1;
          }
        }
      }
    }
  }
  cout << maxSize << endl;
}
