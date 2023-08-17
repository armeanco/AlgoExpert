#include <vector>

int maximumSumSubmatrix(std::vector<std::vector<int>> matrix, int size) {
  int r = matrix.size(), c = matrix[0].size(), res = INT_MIN;
  std::vecto<std::vector<int>> dp(r + 1, std::vector<int>(c + 1, 0));
  for( int i = 1; i < r + 1; ++i ) {
    for( int j = 1; j < c + 1; ++j ) {
      dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  }
  for( int i = 1; i <= r - size + 1; ++i ) {
    for( int j = 1; j <= c - size + 1; ++j ) {
      int v = dp[i + size - 1][j + size - 1] - dp[i - 1][j + size - 1] - dp[i + size - 1][j - 1] + dp[i - 1][j - 1];
      if( v > res ) res = v;
    }
  }
  return res;
} 
