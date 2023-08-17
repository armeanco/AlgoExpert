#include <string>

std::string reverseWordsInString(std::string str) {
  std::string out = "";
  int word = -1;
  for( std::size_t i = 0; i < str.size(); ++i ) {
    if( str[i] == ' ' ) out += ' ';
    else {
      if( i == str.size() - 1 || str[i + 1] == ' ' ) word = i;
      if( i == 0 || str[i - 1] == ' ' ) {
        for(int j = 0; j <= word; ++j ) out += str[j];
        word = -1;
      }
    }
  }
  return out;
}
