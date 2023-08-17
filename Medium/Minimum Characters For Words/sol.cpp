#include <vector>
#include <string>
std::vector<char> minimumCharactersForWords(std::vector<std::string> words) {
    std::vector<int> frequency(126);
	std::vector<char> res;
	for( std::size_t i = 0; i < words.size(); ++i ) {
		std::vector<int> map(126);
		for( std::size_t j = 0; j < words[i].size(); ++j ) {
			map[words[i][j]]++;
			if( frequency[words[i][j]] < map[words[i][j]] ) frequency[words[i][j]] = map[words[i][j]];
		}
	}
	for( std::size_t i = 0; i < frequency.size(); ++i )
		if( frequency[i] > 0 )
			for( int j = 0; j < frequency[i]; ++j )
				res.push_back(i);
	return res;
}
