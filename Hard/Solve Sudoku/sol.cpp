#include <vector>

bool isPresentInCol(int col, int num, std::vector<std::vector<int>> & grid) {
   for (int row = 0; row < 9; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInRow(int row, int num, std::vector<std::vector<int>> &grid) {
   for (int col = 0; col < 9; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num, std::vector<std::vector<int>> &grid) {
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}

bool findEmptyPlace(int &row, int &col, std::vector<std::vector<int>> &grid) {
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (grid[row][col] == 0)
            return true;
   return false;
}

bool isValidPlace(int row, int col, int num, std::vector<std::vector<int>> &grid) {
   return !isPresentInRow(row, num, grid) && !isPresentInCol(col, num, grid) && !isPresentInBox(row - row%3 , col - col%3, num, grid);
}

bool solve(std::vector<std::vector<int>> &grid) {
   int row, col;
   if (!findEmptyPlace(row, col, grid))
      return true;
   for (int num = 1; num <= 9; num++) {     
      if (isValidPlace(row, col, num, grid)) {    
         grid[row][col] = num;
         if (solve(grid))     
            return true;
         grid[row][col] = 0;    
      }
   }
   return false;
}

vector<vector<int>> solveSudoku(vector<vector<int>> board) {
  if( solve(board) ) return board;
  return {};
}
