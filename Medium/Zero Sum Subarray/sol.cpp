#include <vector>

bool zeroSumSubarray(std::vector<int> array) {
  std::unordered_map<int, int> prefix = {{0, 1}};
  int prefix_sum = 0, cnt = 0;
  for( const auto &c : array ) {
    prefix_sum += c;
    cnt += prefix[prefix_sum]++;
  }
  return cnt;
}
