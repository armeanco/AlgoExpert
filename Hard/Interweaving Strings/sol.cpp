#include <vector>
#include <utility>
#include <string>
bool interweavingStrings(std::string one, std::string two, std::string three) {
  std::vector<std::pair<char, int>> a, b;
	std::vector<std::pair<std::string, int>> frequency;
	std::string str = three, compress_a, compress_b;
	std::string st = three;
	std::string precompute = one + two;
	if( precompute == three || two + one == three ) return 1;
	if( precompute.size() > three.size() ) return 0;
	for( std::size_t i = 0; i < one.size(); ++i ) {
		int cnt = 0;
		if( one[i] != one[i + 1] ) {
			a.push_back(std::make_pair(one[i], 1));
		}
		else if( one[i] == one[i + 1] && i + 1 < one.size() ) {
			for( std::size_t j = i + 1; one[j] == one[i]; ++j ) { cnt++; }
			a.push_back(std::make_pair(one[i], cnt == 0 ? 1 : cnt + 1));
			i += cnt;
		}
	}
	for( std::size_t i = 0; i < two.size(); ++i ) {
		int cnt = 0;
		if( two[i] != two[i + 1] ) {
			b.push_back(std::make_pair(two[i], 1));
		}
		else if( two[i] == two[i + 1] && i + 1 < two.size() ) {
			for( std::size_t j = i + 1; two[j] == two[i]; ++j ) { cnt++; }
			b.push_back(std::make_pair(two[i], cnt == 0 ? 1 : cnt + 1));
			i += cnt;
		}
	}
	int nxt = 0, step = 0;
	for( auto it = a.begin(), ti = it + 1; it != a.end(); ++it, ++ti ) {
		int cnt = 0;
		step++;
		std::vector<int> sequence;
		for( std::size_t i = nxt; i < three.size() && step < a.size(); ++i ) {
			if( three[i] == it->first ) { cnt++; sequence.push_back(i); }
			if( three[i + 1] == ti->first && ti != b.end() && i + 1 < three.size() ) { nxt = i + 1; break; }
		}
		if( sequence.size() > 1 ) {
			std::string t;
			for( std::size_t i = 0; i < sequence.size(); ++i ) {
				for( std::size_t j = 0; j < str.size(); ++j ) {
					t += j == sequence[i] ? '0' : str[j];
				}
				frequency.push_back(std::make_pair(t, sequence[i]));
			}
		}
		if( cnt < it->second ) break;
		for( std::size_t j = sequence.size() - 1, k = 0; k < it->second; ++k, --j ) {
			str[sequence[j]] = '0';
		}
		if( step + 1 == a.size() ) {
			int get = 0;
			for( std::size_t i = nxt; i < str.size(); ++i ) { 
				if( str[i] == a[a.size() - 1].first && get < a[a.size() - 1].second ) {
					get++;
					str[i] = '0';
				}
			}
		}
	}
	for( std::size_t i = 0; i < str.size(); ++i ) if( str[i] != '0' ) compress_a += str[i];
	if( compress_a == two ) return 1;
	step = 0, nxt = 0;
	for( auto it = b.begin(), ti = it + 1; it != b.end(); ++it, ++ti ) {
		int cnt = 0;
		step++;
		std::vector<int> sequence;
		for( std::size_t i = nxt; i < three.size() && step < b.size(); ++i ) {
			if( three[i] == it->first ) { cnt++; sequence.push_back(i); }
			if( three[i + 1] == ti->first && ti != b.end() && i + 1 < three.size() ) { nxt = i + 1; break; }
		}
		if( sequence.size() > 1 ) {
			std::string t;
			for( std::size_t i = 0; i < sequence.size(); ++i ) {
				for( std::size_t j = 0; j < st.size(); ++j ) {
					t += j == sequence[i] ? '0' : st[j];
				}
				frequency.push_back(std::make_pair(t, sequence[i]));
			}
		}
		if( cnt < it->second ) break;
		for( std::size_t j = sequence.size() - 1, k = 0; k < it->second; ++k, --j ) st[sequence[j]] = '0';
		if( step + 1 == b.size() ) {
			int get = 0;
			for( std::size_t i = nxt; i < st.size(); ++i ) {
				if( st[i] == b[b.size() - 1].first && get < b[b.size() - 1].second ) {
					get++;
					st[i] = '0';
				}
			}
		}
	}
	for( auto it = frequency.begin(); it != frequency.end(); ++it ) {
		int cnt = 0;
		for( std::size_t j = it->second; j < it->first.size(); ++j ) {
			if( it->first[j] == b[b.size() - 1].first && cnt < b[b.size() - 1].second ) {
				cnt++;
				it->first.erase(it->first.begin() + j);
			}
		}
	}
	for( auto it = frequency.begin(); it != frequency.end(); ++it ) {
		std::string t;
		for( std::size_t i = 0; i < it->first.size(); ++i ) {
			if( it->first[i] != '0' ) {
				t += it->first[i];
			}
		}
		it->first = t;
	}
	for( const auto &c : frequency ) if( two == c.first || one == c.first ) return 1;
	for( std::size_t i = 0; i < st.size(); ++i ) if( st[i] != '0' ) compress_b += st[i];
	if( compress_b == one ) return 1;
	return 0;
}

//Alternative Solution
#include <string>

bool interweavingStrings(std::string one, std::string two, std::string three) {
  if( one.size() + two.size() != three.size() ) return false;
  std::vector<std::vector<bool>> dp(one.size() + 1, std::vector<bool>( two.size() + 1, false));
  dp[0][0] = true;
  for( std::size_t x = 1; x <= one.size(); ++i ) {
    dp[x][0] = one[x - 1] == three[x - 1] && dp[x - 1][0];
  }
  for( std::size_t x = 1; x <= two.size(); ++x ) {
    dp[0][x] = two[x - 1] == three[x - 1] && dp[0][x - 1];
  }
  for( std::size_t x = 1; x <= one.size(); ++x ) {
    for( std::size_t y = 1; y <= two.size(); ++y ) {
      dp[x][y] = (one[x - 1] == three[x + y - 1] && dp[x - 1][y] ) ||
                 (two[y - 1] == three[x + y - 1] && dp[x][y - 1]);
    }
  }
  return dp.back().back();
}
