#include <vector>
#include <limits>

std::vector<int> findThreeLargestNumbers(std::vector<int> array) {
  int smallest = std::numeric_limits<int>::min();
  std::vector<int> res {smallest, smallest, smallest};
  for( const auto &c : array ) {
    if( c > res[2] ) swap( res[2], c );
    if( c > res[1] ) swap( res[1], c );
    if( c > res[0] ) swap( res[0], c );
  }
  return res;
}
