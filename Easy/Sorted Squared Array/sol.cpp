#include <vector>

std::vector<int> sortedSquaredArray(std::vector<int> array) {
  std::vector<int> res(array.size());
  int left = 0, right = array.size() - 1;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    if( std::abs(array[left] > std::abs(array[right]) ) { 
      res[i] = array[left] * array[left];
      left++;
    }
    else {
      res[i] = array[right] * array[right];
      right--;
    }
  }
  return res;
}
