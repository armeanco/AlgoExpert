#include <vector>
float medianOfTwoSortedArrays(std::vector<int> arrayOne, std::vector<int> arrayTwo) {
	float median = 0.0;
	std::vector<int> preprocess = arrayOne;
	auto position = [&](std::vector<int> arr, auto val, auto low, auto high) -> int {
		if( val < arr[low] ) return 0;
	    while( low <= high ) {
        int middle = ( low + high ) / 2;
			  if( arr[middle] == val ) return middle;
			  else if( arr[middle] < val ) low = middle + 1;
			  else high = middle - 1;
		}
		return low;
	};
	for( std::size_t i = 0; i < arrayTwo.size(); ++i ) {
		int pos = position(preprocess, arrayTwo[i], 0, preprocess.size() - 1);
		preprocess.insert(preprocess.begin() + pos, arrayTwo[i]);
	}
    return preprocess.size() % 2 != 0 ? preprocess[preprocess.size() / 2] : (preprocess[preprocess.size() / 2 - 1] + preprocess[preprocess.size() / 2]) / 2.0;
}
