#include <vector>

int maxSubsetSumNoAdjacent(std::vector<int> array) {
  int prev = 0, prv = 0, cur = 0;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    cur = std::max( prv + array[i], prev );
    prv = prev;
    prev = cur;
  }
  return cur;
}
