#include <vector>
std::vector<int> mergeSortedArrays(std::vector<std::vector<int>> arrays) {
	std::vector<int> precompute;
	for( std::size_t i = 0; i < 1; ++i )
		for( std::size_t j = 0; j < arrays[i].size(); ++j ) precompute.push_back(arrays[i][j]);
	auto position = [&](std::vector<int> array, auto val, auto low, auto high) -> int {
		if( val < array[low] ) return 0;
		while( low <= high ) {
			int middle = ( low + high ) / 2;
			if( array[middle] == val ) return middle;
			else if( array[middle] < val ) low = middle + 1;
			else high = middle - 1;	
		}
		return low;
	};
	for( std::size_t i = 1; i < arrays.size(); ++i ) {
		for( std::size_t j = 0; j < arrays[i].size(); ++j ) {
			int pos = position(precompute, arrays[i][j], 0, precompute.size() - 1);
			precompute.insert(precompute.begin() + pos, arrays[i][j]);
		}
	}
	return precompute;
}
