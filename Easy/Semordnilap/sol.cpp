#include <vector>
#inclued <string>
#include <unordered_set>

std::vector<std::vector<std::string>> semordnilap(std::vector<std::string> words) {
  std::unordered_set<std::string> list;
  std::vector<std::vector<std::string>> res;

  for( std::string w : words ) {
    std::string word = w;
    std::reverse(word.begin(), word.end());

    if( list.find(word) != list.end() ) {
      res.push_back( {w, word} );
    }
    list.insert(w);
  }
  return res;
}
