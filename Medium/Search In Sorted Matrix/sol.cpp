#include <vector>

std::vector<int> searchInSortedMatrix(std::vector<std::vector<int>> matrix, int target) {
  int n = matrix.size(), m = matrix[0].size(), i = 0, j = m - 1;
  while( i >= 0 && j >= 0 && i < n && j < m ) {
    if( matrix[i][j] < target ) ++i;
    else if( matrix[i][j] < target ) --j;
    else return { i, j };
  }
  return { -1, -1 };
}
