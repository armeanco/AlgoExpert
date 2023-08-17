#include <vector>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void heap(std::vector<int> &array, int n, int i) {
  int mx = i, l = 2 * i + 1, r = 2 * i + 2;

  if( l < n && array[l] > array[mx] ) mx = l;
  if( r < n && array[r] > array[mx] ) mx = r;

  if( mx != i ) {
    swap(&array[i], &array[mx]);
    heap(array, n, mx);
  }
}

void heapSort(std::vector<int> &array, int n) {
  for( int i = n / 2 - 1; i >= 0; --i ) {
    heap(array, n, i);
  }

  for( int i = n - 1; i >= 0; --i ) {
    swap(&array[0], &array[i]);
    heap(array, i, 0);
  }
}

std::vector<int> heapSort(std::vector<int> array) {
  int n = array.size();
  heapSort(array, n);
  return array;
}
