#include <vector>
#include <algorithm>
#include <cmath>

int tandemBicycle(std::vector<int> redShirtSpeeds, std::vector<int> blueShirtSpeeds, bool fastest) {
  std::sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
  std::sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
  int total = 0;
  for( std::size_t i = 0; i < redShirtSpeeds.size(); ++i ) {
    if( fastest ) total += std::max( redShirtSpeeds[i], blueShirtSpeeds[blueShirtSpeeds.size() - i - 1] );
    else total += std::max( redShirtSpeeds[i], blueShirtSpeeds[i] );
  }
  return total;
}
