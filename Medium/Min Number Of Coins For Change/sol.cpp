#include <vector>

int minNumberOfCoinsForChange(int n, std::vector<int> denoms) {
  int t[n + 1];
  t[0] = 0;
  for( int i = 1; i <= n; ++i ) t[i] = 1e6;
  for( int i = 1; i <= n; ++i ) {
    for( std::size_t j = 0; j < denoms.size(); ++j ) {
      if( denoms[j] <= i ) {
        int r = t[i - denoms[j]];
        if( r != 1e6 && r + 1 < t[i] ) t[i] = r + 1;
      }
    }
  }
  if( t[n] == 1e6 ) return -1;
  return t[n];
}
