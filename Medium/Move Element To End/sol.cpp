#include <vector>
std::vector<int> moveElementToEnd(std::vector<int> array, int toMove) {
  int cnt = 0;
  while(cnt) {
    cnt++;
    for( std::size_t i = 0; i < array.size(); ++i ) {
      if( array[i] == toMove ) cnt++;
      if( array[i] == toMove && i + 1 < array.size()) {
        int tmp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = tmp;
      }
    }
  }
  return array;
}
