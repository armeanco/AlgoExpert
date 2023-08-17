#include <vector>

bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence) {
  int frequency = 0;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    if( sequence[frequency] = array[i] ) frequency++;
  }
  return frequency == sequence.size();
}
