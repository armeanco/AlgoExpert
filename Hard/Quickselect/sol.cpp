#include <vector>

int select(std::vector<int> &array, int l, int h, int k) {
  auto sort = [&](std::vector<int> array, int l, int h) -> int {
    int i = l, j = l;
    while( j < h ) {
      if( array[j] < array[h] ) swap( array[i++], array[j] );
      j = j + 1;
    }
    swap( array[i], array[h] );
    return i;
  };
  if( l <= h ) {
    int q = sort( array, l, h );
    if( q == k ) return array[q];
    else if( q < k ) return select( array, q + 1, h, k );
    else return select( array, l, q - 1, k );
  }
  return -1;
}

int quickselect(std::vector<int> array, int k) {
  int n = array.size();
  return select( array, 0, n - 1, k - 1 );
}
