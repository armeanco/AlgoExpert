#include <vector>
#include <algorithm>
std::vector<std::vector<int>> getPermutations(std::vector<int> array) {
  std::sort(array.begin(), array.end());
  std::vector<std::vector<int>> sequence;
  if( array.empty() ) return sequence;
  do {
    std::vector<int> t;
    for( std::size_t i = 0; i < array.size(); ++i ) t.push_back(array[i]);
    sequence.push_back(t);
  } while(std::next_permutation(array.begin(), array.end()));
  return sequence;
}
