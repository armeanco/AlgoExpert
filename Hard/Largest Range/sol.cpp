#include <vector>
std::vector<int> largestRange(std::vector<int> array) {
  if( array.size() == 1 ) return { array[0], array[0] };
  std::sort(array.begin(), array.end());
  array.erase(std::unique(array.begin(), array.end()), array.end());
  int mx = 0;
  std::vector<std::vector<int>> sequence;
  for( std::size_t i = 0; i < array.size(); ++i ) {
      std::vector<int> t;
      for(std::size_t j = i; array[j] + 1 == array[j + 1]; ++j ) {
          t.push_back(array[j]), i = j;
      }
      if( static_cast<int>(t.size()) > mx ) mx = static_cast<int>(t.size());
      sequence.push_back(t);
  }
  for( const auto &c : sequence ) if( c.size() == mx ) return {c[0],c[c.size() - 1] + 1};
  return {};
}
