#include <string>

std::string runLengthEncoding(std::string str) {
  std::string ans;
  int iterator = 0;
  int nxt = 0;
  for( std::size_t i = 0; i < str.size(); ++i ) {
    if( str[i] != str[i + 1]) ans += std::to_string(1) + str[i];
    while( str[i] == str[i + 1] ) {
      iterator++;
      i++;
      nxt++;
      if( iterator == 9 || str[i] != str[i + 1] )  {
        ans += std::to_string(iterator == 9 ? 9 : iterator + 1 ) + str[i];
        iterator = 0;
      }
    }
    if( nxt + 1 == str.size() && nxt > 200 ) ans += std::to_string(1) + str[i];
  }
  return ans;
}
