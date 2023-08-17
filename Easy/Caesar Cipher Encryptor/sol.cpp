#include <string>
#include <vector>

std::string caesarCypherEncryptor(std::string str, int key) {
  std::vector<char> ls;
  for( std::size_t i = 0; i < str.size(); ++i ) {
    int tmp = str[i] - 'a';
    int s = ( tmp + key ) % 26 + 'a';
    ls.push_back(static_cast<char>(s));
  }
  return std::string(ls.begin(), ls.end());
}
