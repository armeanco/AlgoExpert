#include <vector>
std::vector<int> threeNumberSort(std::vector<int> array, std::vector<int> order) {
  int a = 0, b = 0, c = 0;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    if( array[i] == order[0] ) a++;
    if( array[i] == order[1] ) b++;
    if( array[i] == order[2] ) c++;
  }
  int i = -1;
  while( a-- > 0 ) {
    i++;
    array[i] = order[0];
  }
  while( b--> 0 ) {
    i++;
    array[i] = order[1];
  }
  while( c--> 0 ) {
    i++;
    array[i] = order[2];
  }
  return array;
}
