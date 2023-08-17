#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<std::vector<int>> fourNumberSum(std::vector<int> array, int targetSum) {
  std::unordered_map<int, std::vector<std::vector<int>>> allP;
  std::vector<std::vector<int>> quad{};
  for( std::size_t i = 1; i < array.size(); ++i ) {
    for( std::size_t j = i + 1; j < array.size(); ++j ) {
      int cur = array[i] + array[j];
      int diff = targetSum - cur;
      if( allP.find(diff) != allP.end() ) {
        for( std::vector<int> p : allP[diff] ) {
          p.push_back(array[i]);
          p.push_back(array[j]);
          quad.push_back(p);
        }
      }
    }
    for( int k = 0; k < i; ++k ) {
      int cur = array[i] + array[k];
      if( allP.find(cur) == allP.end() ) {
        allP[cur] = std::vector<std::vector<int>>{{ array[k], array[i] }};
      } else {
        allP[cur].push_back(std::vector<int>{ array[k], array[i] });
      }
    }
  }
  return quad;
}
