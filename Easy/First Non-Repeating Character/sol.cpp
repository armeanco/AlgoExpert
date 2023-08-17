#include <string>

int firstNonRepeatingCharacter(std::string string) {
  int cnt[26] = {0};
  for( auto &c : string ) cnt[c - 'a']++;
  int nxt = 0;
  for( auto &c : string ) {
    if( cnt[c - 'a'] == 1 ) return nxt;
    nxt++;
  }
  return -1;
}
