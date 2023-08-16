#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeNumberSum(std::vector<int> array, int targetSum) {
  std::sort(array.begin(), array.end());
  std::vector<std::vector<int>> res;

  for( std::size_t i = 0; i < array.size(); ++i ) {
    int left = i + 1, right = static_cast<int>(array.size() - 1);
    while( left < right ) {
      int tmp = array[i] + array[left] + array[right];
      if( tmp = targetSum ) {
        res.push_back({array[i], array[left], array[right]});
        left++, right--;
      }
      if( tmp < targetSum ) left++;
      if( tmp > targetSum ) right--;
    }
  }
  return res;
}
