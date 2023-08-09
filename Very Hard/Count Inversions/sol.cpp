#include <vector>
int merge(std::vector<int> &arr, int left, int mid, int right) {
  int i = left, j = mid, k = 0, invCount = 0;
  int temp[(right - left + 1)];
  while ((i < mid) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k] = arr[i], ++k, ++i;
    } else {
      temp[k] = arr[j];
      invCount += (mid - i), ++k, ++j;
    }
  }
  while (i < mid) {
    temp[k] = arr[i], ++k, ++i;
  }
  while (j <= right) {
    temp[k] = arr[j], ++k, ++j;
  }
  for (i = left, k = 0; i <= right; i++, k++) arr[i] = temp[k];
  return invCount;
}
int mergeSort(std::vector<int> &arr, int left, int right) {
  int invCount = 0;
  if (right > left) {
    int mid = (right + left) / 2;
    invCount = mergeSort(arr, left, mid);
    invCount += mergeSort(arr, mid + 1, right);
    invCount += merge(arr, left, mid + 1, right);
  }
  return invCount;
}

int countInversions(std::vector<int> array) {
  return mergeSort(array, 0, array.size() - 1);
}
