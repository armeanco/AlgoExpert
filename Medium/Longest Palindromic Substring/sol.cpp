#include <string>
std::string longestPalindromicSubstring(std::string str) {
  	std::vector<std::string> sequence;
    if( str.size() == 1 ) return str;
	for( std::size_t i = 0; i < str.size(); ++i ) {
		std::string s = "", f;
		s += str[i];
		for( std::size_t j = i + 1; j < str.size(); ++j ) {
			s += str[j], f = s;
			std::reverse(f.begin(), f.end());
			if( f == s ) sequence.push_back(s);
		}
	}
	std::sort(sequence.begin(), sequence.end(), [](auto a, auto b) {		
			return a.size() > b.size();
	});
	return sequence[0];
}
