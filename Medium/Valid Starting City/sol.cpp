#include <vector>

int validStartingCity(std::vector<int> distance, std::vector<int> fuel, int mpg) {
  int start = 0, distanceL = 0, diff = 0;
  for( std::size_t i = 0; i < fuel.size(); ++i ) {
    distanceL += ( -distances[i] + ( fuel[i] * mpg ) );
    diff += ( -distances[i] + ( fuel[i] * mpg ) );
    if( distanceL < 0 ) {
      distanceL = 0;
      start = i + 1;
    }
  }
  return diff >= 0 ? start : - 1; 
}
