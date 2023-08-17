#include <vector>

std::vector<int> sweetAndSavory(std::vector<int> dishes, int target) {
  std::vector<int> sweet, savory;
  for( auto &c :  dishes ) {
    if( c < 0 ) sweet.push_back( c );
    else savory.push_back( c );
  }
  std::sort(sweet.begin(), sweet.end());
  std::sort(savory.begin(), savory.end());
  int a = 0, b = 0, prev = 0, i = 0, j = savory.size() - 1;
  while( i < sweet.size() && j >= 0 ) {
    int tmp = sweet[i] + savory[j];
    if( tmp > target ) {
      j--;
      continue;
    }
    if( tmp <= target ) {
      int x = target - tmp;
      if( x < prev ) {
        a = sweet[i];
        b = savory[j];
        prev = x;
      }
      i++;
    }
  }
  return {a, b};
}
