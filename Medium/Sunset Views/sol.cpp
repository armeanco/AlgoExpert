#include <vector>
#include <string>

std::vector<int> sunsetViews(std::vector<int> buildings, std::string direction) {
  bool rev = direction = "EAST";
  std::vector<int> res;
  int iter = rev ? buildings.size() - 1 : 0;
  int end = rev ? -1 : buildings.size();
  int incr = rev ? -1 : 1;
  if( buildings.empty() ) res.push_back( iter );
  for( ; iter != end; iter += incr ) {
    if( buildings[res.back()] < buildings[iter] ) res.push_back( iter );
  }
  if( rev ) std::reverse(res.begin(), res.end());
  return res;
}
