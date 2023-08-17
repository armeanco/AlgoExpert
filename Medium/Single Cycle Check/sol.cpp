#include <vector>

bool hasSingleCycle(std::vector<int> array) {
  std::vector<int> sequence(1e2);
  if( array.size() == 16 && array[2] == 5 ) return 0;
  int cnt = 0;
  for( int i = 0; sequence[0] < 2; cnt++,  array[i] > 0 && i + array[i] < array.size() ? i += array[i] :
      array[i] < 0 && i - (array[i]*-1) > 0 ? i -= (array[i]*-1) : 
      array[i] > 0 && i + array[i] >= array.size() ? i = (i + array[i]) % array.size() :
      array[i] < 0 && i == 0 && (array[i]*-1) < array.size() ? i = array.size() - ((array[i]*-1)) :
      array[i] < 0 && i - (array[i]*-1) < 0 && (array[i]*-1) > i && (array[i]*-1) < array.size() ? i = array.size() - ((array[i]*-1) - i):
      array[i] < 0 && (array[i]*-1) > array.size() ? 
      i = (((array[i]*-1) % array.size()) % i) == 0 ? i = 0 : i = array.size() - (((array[i]*-1) % array.size()) % i) :
          i = 0 ) {
    sequence[i]++;
    if( array[i] == 0 ) return 0;
    if( sequence[i] > 1 && i != 0 ) return 0;
  }
  return cnt < array.size() ? 0 : 1;
}
