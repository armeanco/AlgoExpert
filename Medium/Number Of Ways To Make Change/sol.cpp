#include <vector>
int numberOfWaysToMakeChange(int n, std::vector<int> denoms) {
  int t[n + 1];
  std::memset(t, 0, sizeof(t));
  t[0] = 1;
  for( std::size_t i = 0; i < denoms.size(); ++i ) {
    for( int j = 1; j <= n; ++j )
      if( denoms[i] <= j)
        t[j] += t[j - denoms[i]];
  }
  return t[n];
}
