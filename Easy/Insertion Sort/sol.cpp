#include <vector>
std::vector<int> insertionSort(std::vector<int> array) {
  for( std::size_t i = 1; i < array.size(); ++i ) {
    int id = array[i];
    int j = i - 1;
    while( id < array[j] && j >= 0 ) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = id;
  }
  return array;
}
