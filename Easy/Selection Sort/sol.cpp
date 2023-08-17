#include <vector>

std::vector<int> selectionSort(std::vector<int> array) {
  auto swap = [&](auto a, auto b) -> void {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  };
  for( std::size_t i = 0; i < array.size(); ++i ) {
    int idx = i;
    for( std::size_t j = i + 1; j < array.size(); ++j ) {
      if( array[j] < array[idx] ) {
        idx = j;
      }
    }
    swap(&array[i], &array[idx]);
  }
  return array;
}
