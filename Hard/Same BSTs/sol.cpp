#include <vector>
struct BST {
  int value;
  BST* right, *left;
  
  BST(int value) {
    this->value = value;
    right = nullptr, left = nullptr;
  }

  BST* insert(int value) {
    if( value < this->value ) {
      if( left == nullptr ) left = new BST(value);
      else left->insert(value);
    }
    if( value >= this->value ) {
      if( right == nullptr ) right = new BST(value);
      else right->insert(value);
    }
    return this;
  }

  static bool isSame(BST* rootOne, BST* rootTwo) {
    if( rootOne == nullptr && rootTwo == nullptr ) return 1;
    else if( rootOne == nullptr || rootTwo == nullptr ) return 0;
    else {
      if( rootOne->value == rootTwo->value && isSame(rootOne->left, rootTwo->left) && isSame(rootOne->right, rootTwo->right)) return 1;
      else
        return 0;
    }
  }
};

bool sameBsts(std::vector<int> arrayOne, std::vector<int> arrayTwo) {
  BST* rootOne = new BST(arrayOne[0]), *rootTwo = new BST(arrayTwo[0]);
  for( std::size_t i = 1; i < arrayOne.size(); ++i ) rootOne->insert(arrayOne[i]);
  for( std::size_t i = 1; i < arrayTwo.size(); ++i ) rootTwo->insert(arrayTwo[i]);
  return BST::isSame(rootOne, rootTwo);
}
