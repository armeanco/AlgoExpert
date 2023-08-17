#include <vector>
#include <algorithm>
bool classPhotos(std::vector<int> redShirtHeights, std::vector<int> blueShirtHeights) {
  std::sort(redShirtHeights.begin(), redShirtHeights.end());
  std::sort(blueShirtHeights.begin(), blueShirtHeights.end());
  if( redShirtHeights[0] < blueShirtHeights[0] && redShirtHeights[redShirtHeights.size() - 2] > blueShirtHeights[blueShirtHeights.size() - 2] ) return false;
  if( redShirtHeights[0] > blueShirtHeights[0] && redShirtHeights[redShirtHeights.size() - 1] > blueShirtHeights[blueShirtHeights.size() - 1] ) return true;
  if( redShirtHeights[0] < blueShirtHeights[0] && redShirtHeights[redShirtHeights.size() - 1] < blueShirtHeights[blueShirtHeights.size() - 1] ) return true;
  return false;
}
