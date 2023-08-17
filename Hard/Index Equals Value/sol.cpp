#include <vector>
int indexEqualsValue(std::vector<int> array) {
  	int high = array.size() - 1, low = 0, ans = -1;
	while( low <= high ) {
		int middle = ( low + high ) / 2;
		if( array[middle] == middle ) { ans = middle; high = middle - 1; } 
		else if( array[middle] < middle ) {
			low = middle + 1;
		}
		else {
			high = middle - 1;
		}
	}
	return ans;
}
