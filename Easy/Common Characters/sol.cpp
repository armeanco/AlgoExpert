#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

std::vector<std::string> commonCharacters(std::vector<std::string> strings) {
  std::unordered_map<char> common(strings[0].begin(), strings[0].end());
  for( auto &c : strings ) {
    unordered_set<char> tmp;
    for( auto &s : c ) 
      if( common.count(c) ) tmp.insert( c );
    common.swap( tmp );
  }
  std::vector<std::string> res;
  for( auto &c : common ) res.emplace_back( 1, c );
  return res;
}
