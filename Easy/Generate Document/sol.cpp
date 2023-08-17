#include <string>
#include <vector>

bool generateDocument(std::string characters, std::string document) {
  if( characters.size() == 0 ) return 0;
  std::vector<int> freq_c( 150 ), freq_d( 150 );
  for( std::size_t i = 0; i < characters.size(); ++i ) {
    freq_c[characters[i]]++;
  }
  for( std::size_t i = 0; i < document.size(); ++i ) {
    freq_d[document[i]]++;
  }
  for( std::size_t i = 0; i < document.size(); ++i ) {
    if( freq_c[document[i]] < freq_d[document[i]] ) return 0;
  }
  return 1;
}
