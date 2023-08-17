#include <vector>

int binarySearch(std::vector<int> array, int target) {
  int low = 0, high = array.size() - 1;
  while( low <= high ) {
    int middle = ( low + high ) / 2; 
    if( array[middle] < target )
      low = middle + 1;
    else if( array[middle] == target )
      return middle;
    else 
      high = middle - 1;
  }
  return -1;
}
