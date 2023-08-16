//O(N)Time|O(M)Space
#include <vector>

int firstDuplicateValue(std::vector<int> array) {
  std::vector<int> frequency(1e3);
  for( std::size_t i = 0; i < array.size(); ++i ) {
    frequency[array[i]]++;
    if( frequency[array[i]] > 1 ) return array[i];
  }
  return -1; 
}

//O(N)Time|O(1)Space
#include <vector>

int firstDuplicateValue(std::vector<int> array) {
  for( auto c : array ) {
    if( array[std::abs(c) - 1] < 0 ) return std::abs(c);
    array[std::abs(c) - 1] *= -1;
  }
  return -1;
}
