#include <vector>

int bestSeat(std::vector<int> seats) {
  int cnt = 0, max = 0, best = -1, i = seats.size() - 1;
  while( i >= 0 ) {
    if( seats[i] == 0 ) cnt++;
    else {
      if( cnt >= max ) {
        max = cnt;
        if( cnt ) best = i + ( cnt + 1 ) / 2;
      }
      cnt = 0;
    }
    --i;
  }
  return best;
}
