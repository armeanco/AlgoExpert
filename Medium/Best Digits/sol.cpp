#include <string>
std::string bestDigits(std::string number, int numDigits) {
  int cnt = 0;
  for( std::size_t i = 0; i < number.size(); ++i ) if( number[i] <= number[i + 1] ) cnt++;
  if( cnt == 0 ) {
    while( numDigits > 0 ) {
      for( std::size_t i = number.size() - 1; i >= 0; --i ) {
        if( number[i] <= number[i - 1] && i - 1 >= 0 ) {
          number.erase(number.begin() + i);
          numDigits--;
          break;
        }
      }
    }
  }
  while( numDigits > 0 ) {
    for( std::size_t i = 0; i < number.size(); ++i ) {
      if( number[i] <= number[i + 1] && i + 1 < number.size() ) {
        number.erase(number.begin() + i);
        numDigits--;
        break;
      }
    }
  }
  return number;
}
