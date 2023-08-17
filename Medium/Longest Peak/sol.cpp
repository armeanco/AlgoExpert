#include <vector>

int longestPeak(std::vector<int> array) {
  int n = array.size(), i = 1, ans = 0;
  while( i < n ) {
    int cnt = 1;

    if( array[i - 1] >= array[i] ) { i++; continue; }
    while( i < n && array[i - 1] < array[i] ) { i++; cnt++; }
    if( i >= n || array[i - 1] == array[i] ) continue;
    while( i < n && array[i - 1] > array[i] ) { i++; cnt++; }

    ans = std::max( ans, cnt );
  }
  return ans;
}
