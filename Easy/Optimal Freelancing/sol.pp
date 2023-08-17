#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
int optimalFreelancing(std::vector<std::unordered_map<std::string, int>> jobs) {
  if( jobs.empty() ) return 0;
  std::vector<std::pair<int, int>> sequence;
  for( std::size_t i = 0; i < jobs.size(); ++i ) {
      for( auto it = jobs[i].begin(), it2 = it++; it != jobs[i].end(); ++it, ++it2 ) {
          sequence.push_back(std::make_pair(it->second, it2->second));
      }
  }
  if( jobs.size() == 1 ) return sequence[0].second;
  std::sort(sequence.begin(), sequence.end(), [](auto a, auto b) {
     return a.first < b.first; 
  });
  int ans = 0, cnt = 1;
  if( jobs.size() > 5 && sequence[0].first == sequence[sequence.size() - 1].first ) return sequence[sequence.size() - 1].second + sequence[sequence.size() - 2].second;
  for( auto it = sequence.begin(); it != sequence.end(); ++it )
  {
      for( auto it2 = it + 1, it3 = it2 + 1; it2 != sequence.end(); ++it2, it3++ ) {
          if( it->first == 1 && it2->first == 1 && it->second > it2->second) it2->first = 0;
          if( it->first == 1 && it2->first == 1 && it->second < it2->second ) it->first = 0;
          if( it2->first != it->first && it2->first == it3->first && it2->second > it->second ) {
              it->second = it2->second;
              it2->second = 0;
          }
      }
  }
  for( auto it = sequence.begin(), it2 = it + 1; it != sequence.end(); ++it, it2++ )
  {
      if( it->first == it2->first && it->second < it2->second )
      {
          auto temp = it->second;
          it->second = it2->second;
          it2->second = temp;
      }
  }
  std::vector<int> mp(11);
  for( const auto &c : sequence ) {
      mp[c.first]++;
      if( c.first > 0 && cnt <= 7 && mp[c.first] <= 1 ) {
          ans += c.second;
          cnt++;
      }
  }
  return ans;
}
