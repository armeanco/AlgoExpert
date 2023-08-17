#include <vector>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int recall(std::vector<int> &array, int low, int high) {
  int p = array[high];
  int i = low - 1;

  for( int j = low; j < high; ++j ) {
    if( array[j] <= p ) {
      i++;

      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return i + 1;
}

void quickSort(std::vector<int> &array, int low, int high) {
  if( low < high ) {
    int p = recall(array, low, high);
    quickSort(array, low, p - 1);
    quickSort(array, p + 1, high);
  }
}

std::vector<int> quickSort(std::vector<int> array) {
  int s = array.size();
  quickSort(array, 0, s - 1);
  return array;
}
