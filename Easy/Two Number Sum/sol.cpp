#include <vector>
#include <set>

std::vector<int> twoNumberSum(std::vector<int> array, int targetSum) {
  std::set<int> s;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    int x = targetSum - array[i];
    if( s.find(x) != s.end() ) { return {array[i], y}; }
    s.insert(array[i]);
  }
  return {};
}
