//O(N)Time|O(M)Space
#include <vector>
#include <algorithm>

int majorityElement(std::vector<int> array) {
  std::vector<int> freq(1e4);
  if( array.size() == 1 ) return array[0];
  int mx = 0, ans = 0;
  for( std::size_t i = 0; i < array.size(); ++i ) {
    freq[array[i]]++;
    if( freq[array[i]] > mx ) {
      mx = freq[array[i]];
      ans = array[i];
    }
  }
  return ans;
}

//O(N)Time|O(1)Space
#include <vector>

int majorityElement(std::vector<int> array) {
  int majority = 0, cnt = 0;
  for( const auto &c : array ) {
    if( cnt == 0 ) {
      majority = c, cnt = 1;
    }
    else if( c == majority ) cnt++;
    else cnt--;
  }
  return majority;
}
