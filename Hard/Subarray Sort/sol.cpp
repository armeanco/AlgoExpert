#include <vector>
std::vector<int> subarraySort(std::vector<int> array) {
  std::vector<int> cnt;
  int mx = 0, nx = 10;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    for( std::size_t j = i + 1; j < array.size(); ++j ) {
      if( array[i] > array[j] && j < array.size()) {
        cnt.push_back(i);
        cnt.push_back(j);
        if( j > mx ) mx = j;
        if( i < nx ) nx = i;
      }
    }
  }
  if( cnt.empty() ) return {-1, -1};
  return {nx, mx};
}
