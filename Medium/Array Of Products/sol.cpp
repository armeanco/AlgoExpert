#include <vector>

std::vector<int> arrayOfProducts(std::vector<int> array) {
  std::vector<int> res;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    int left = i - 1, right = i + 1, prod = 1;
    while( left >= 0 ) prod *= array[left--];
    while( right < static_cast<int>(array.size()) ) prod *= array[right++];
    res.push_back(prod);
  }
  return res;
}
