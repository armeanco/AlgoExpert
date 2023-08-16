#include <vector>
bool isMonotonic(std::vector<int> array) {
  int inc = 0, dec = 0;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    if( array[i] <= array[i + 1] && i + 1 < array.size() ) inc++;
    if( array[i] >= array[i + 1] && i + 1 < array.size() ) dec++; 
  }
  return array.empty() ? 1 : inc == array.size() - 1 || dec == array.size() - 1;
}
