#include <vector>

int kadanesAlgorithm(std::vector<int> array) {
  int nxt = -1e5, prv = 0;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    prv += array[i];
    if( nxt < prv ) nxt = prv;
    if( prv < 0 ) prv = 0;
  }
  return nxt;
}
