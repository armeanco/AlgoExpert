//Binary Insertion Sort O(n log(n))
#include <vector>
std::vector<int> rightSmallerThan(std::vector<int> array) {
  if( array.empty() ) return {};
  std::vector<int> frequency = {array[array.size() -1]}, result(array.size());
  
  auto bs = [&](std::vector<int> a, int item, int low, int high) {
    while( low <= high ) { 
      int mid = low + ( high - low) / 2; 
      if( a[mid] == item ) {
        while( a[mid] == item ) {
          low = mid + 1;
          if( a[mid + 1] != item ) return mid + 1;
        }
      }
      if( a[mid] < item ) high = mid - 1; 
      else low = mid + 1; 
    } 
    return low;   
  };
  
  for( std::size_t i = 1, j = array.size() - 1; i < array.size(); ++i, --j ) {
    int loc = bs( frequency, array[j - 1], 0, frequency.size() - 1 );
    frequency.insert( frequency.begin() + (loc < 0 ? loc + 1 : loc), array[j - 1] );
    result[j - 1] = frequency.size() - ( loc + 1 ); 
  }
  return result;
}

//Binary Sort Tree O(n log(n))
#include <vector>
struct BST {
  int value, leftSubSize;
  BST *left, *right;

  BST(int value) {
    this->value = value;
    leftSubSize = 0, left = nullptr, right = nullptr;
  }

  void insert(int value, int idx, std::vector<int> &counts, int nums = 0) {
    if( value < this->value ) {
      leftSubSize++;
      if( left == nullptr ) {
        left = new BST( value );
        counts[idx] = nums;
      } else {
        left->insert( value, idx, counts, nums );
      }
    } else {
      nums += leftSubSize;
      if( value > this->value )
        nums++;
      if( right == nullptr ) {
        right = new BST( value );
        counts[idx] = nums;
      } else {
        right->insert( value, idx, counts, nums );
      }
    }
  }
};

std::vector<int> rightSmallerThan(std::vector<int> array) {
  if( array.empty() ) return {};
  std::vector<int> counts = array;
  int idx = array.size() - 1;
  BST *bst = new BST( array[idx] );
  counts[idx] = 0;
  for( int i = idx - 1; i >= 0; i-- ) bst->insert( array[i], i, counts );
  delete bst;
  return counts;
}
