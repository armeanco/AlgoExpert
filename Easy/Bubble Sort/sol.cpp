#include <vector>

std::vector<int> bubbleSort(std::vector<int> array) {
  for( std::size_t i = 0; i < array.size(); ++ i ) {
      if( array[i] > array[i + 1] && i + 1 < array.size() ) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
  }
  return array;
}
