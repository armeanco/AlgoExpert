//Sub-Optimal Solution O(N*126*log(bigString))
#include <vector>
#include <string>
std::string smallestSubstringContaining(std::string bigString, std::string smallString) {
  if( smallString.empty() || smallString.size() > bigString.size() ) return "";
	if( smallString.size() == 1 ) return smallString;
	std::vector<int> frequency(126);
	std::vector<std::vector<int>> hash(126, std::vector<int>(0));
	int start = 1e6, end = 0, upper_b = 0, lower_b = 1e6, max_size = 1e6, min_index = 0, len = 1e6;
	for( std::size_t i = 0; i < smallString.size(); ++i ) {
		frequency[smallString[i]]++;
		if( static_cast<int>(smallString[i]) > end )   end   = static_cast<int>(smallString[i]);
		if( static_cast<int>(smallString[i]) < start ) start = static_cast<int>(smallString[i]); 
	}
	for( std::size_t i = 0; i < bigString.size(); ++i ) {
		if( frequency[bigString[i]] > 0 ) { 
			hash[bigString[i]].push_back(i);
			if( frequency[bigString[i]] < max_size ) max_size = frequency[bigString[i]];
		}
	}
	for( std::size_t i = 0; i < smallString.size(); ++i ) if( hash[smallString[i]].size() < frequency[smallString[i]] ) return "";
	for( std::size_t i = start; i <= end; ++i ) {
		for( std::size_t j = 0 ; j < hash[i].size(); ++j ) {
			if( hash[i].size() == 1 && hash[i][0] == 0 ) min_index = 1;
			if( hash[i].size() > 0 && frequency[i] <= hash[i].size() ) {
				if( lower_b > hash[i][0] ) lower_b = hash[i][0];
				if( upper_b < hash[i][hash[i].size() - 1] ) upper_b = hash[i][hash[i].size() - 1];
			}
		}
	}
	auto bs = [&](std::vector<int> sequence, auto target, auto low, auto high) -> int {
		while( low <= high ) {
			int middle = ( low + high ) / 2;
			if( sequence[middle] == target ) return middle;
			else if( sequence[middle] < target ) low = middle + 1;
			else high = middle - 1;
		}
		return low;
	};
	auto position = [&](std::vector<int> sequence, auto target, auto low, auto high) -> int {
		if( target == 0 ) return 0;
		if( target > sequence[sequence.size() - 1] ) return sequence.size();
		if( sequence.size() == 1 ) return 0;
		while( low <= high ) {
			int middle = ( low + high ) / 2;
			if( sequence[middle + 1] > target && sequence[middle] < target ) return middle + 1;
			else if( sequence[middle] < target ) low = middle + 1;
			else high = middle - 1;
		}
		return low;
	};
	std::vector<int> range(2);
	for( std::size_t i = lower_b == 1e6 ? 0 : lower_b == upper_b ? 0 : lower_b; upper_b < bigString.size() ? i <= upper_b : i < upper_b; ++i ) {
		int min = 0, max = 0;
		if( hash[bigString[i]].size() > 0 && frequency[bigString[i]] > 0 ) {
			min = i;
			if( hash[bigString[i]].size() == 1 ) max = i;
			if( hash[bigString[i]].size() > 1 ) {
				int loc = bs(hash[bigString[i]], i, 0, hash[bigString[i]].size() - 1 );
				if( loc + frequency[bigString[i]] > hash[bigString[i]].size() ) break;
				max = hash[bigString[i]].size() == 1 ? hash[bigString[i]][0] : hash[bigString[i]][loc + frequency[bigString[i]] - 1];
			}
		}
		for( std::size_t j = start; j <= end + 1; ++j ) {
			int pos = 0;
			if( frequency[bigString[i]] > 0 && hash[j].size() > 0 && hash[j] != hash[bigString[i]] ) {
				if( max < 0 ) break;
				pos = position(hash[j], min, 0, hash[j].size() - 1);
				if( pos + frequency[j] - 1 >= hash[j].size() ) { min = 0; max = 0; break; }
				if( hash[bigString[i]][hash[bigString[i]].size() - 1] < i ) break;
				if( max < hash[j][pos + frequency[j] - 1] ) max = hash[j][pos + frequency[j] - 1];
			}
		}
		if( max - min >= smallString.size() - 1 && (max - min) < len && len > 0 ) {
			len = max - min;
			range[0] = lower_b == 0 && min_index ? 0 : min, range[1] = max;
		}
	}
	return bigString.substr(range[0], range[1] - range[0] + 1);
}
