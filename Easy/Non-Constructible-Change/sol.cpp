#include <vector>

int nonConstructibleChange(std::vector<int> coins) {
  int mx = 0;
  std::sort(coins.begin(), coins.end());
  for( std::size_t i = 0; i < coins.size(); ++i ) {
    if( coins[i] > (mx + 1)) return mx + 1;
    else mx += coins[i];
  }
  return mx + 1;
}
