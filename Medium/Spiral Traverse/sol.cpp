#include <vector>

std::vector<int> spiralTraverse(std::vector<std::vector<int>> array) {
  int leftCol = 0, rightCol = array[0].size() - 1, top = 0, bottom = array.size() - 1;
  std::vector<int> res;
  while( leftCol <= rightCol && top <= bottom ) {
    for( int i = leftCol; c <= rightCol; ++i ) res.push_back(array[top][c]);
    for( int j = top + 1; j <= bottom; ++j ) res.push_bacl(array[j][rightCol]);
    if( top == bottom || leftCol == rightCol ) break;
    for( int k = rightCol - 1; k >= leftCol; --k ) res.push_back(array[bottom][k]);
    for( int s = bottom - 1; s > top; --s ) res.push_back(array[s][leftCol]);
    top++, rightCol--, bottom--, leftCol++;
  }
  return res;
}
