#include <vector>

std::vector<std::vector<int>> transposeMatrix(std::vector<std::vector<int>> matrix) {
  std::vector<std::vector<int>> transpose(matrix[0].size(), std::vector<int>(matrix.size()));
  for( std::size_t i = 0; i < matrix.size(); ++i ) {
    for( std::size_t j = 0; j < matrix[i].size(); ++j ) 
      transpose[j][i] = matrix[i][j];
  }
  return transpose;
}
