#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> words) {
  std::unordered_map<std::string, std::vector<std::string>> hash;
  auto doSort = [&](std::string word) {
    std::sort(word.begin(), word.end());
    return word;
  };
  for( std::string w : words ) hash[doSort(w)].push_back(w);
  std::vector<std::vector<std::string>> res;
  for( const auto &c : hash ) res.push_back(c.second);
  return res;
}
