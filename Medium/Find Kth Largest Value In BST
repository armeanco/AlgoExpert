using namespace std;

// This is an input class. Do not edit.
class BST {
 public:
  int value;
  BST* left = nullptr;
  BST* right = nullptr;

  BST(int value) { this->value = value; }
};

int findKthLargestValueInBst(BST* tree, int k) {
  BST* current = tree;
  BST* Kth = nullptr;

  int cnt = 0;

  while( current != nullptr ) {
    if( current->right == nullptr ) {
      if( ++cnt == k ) Kth = current;
      current = current->left;
    } else {
      BST* successor = current->right;
      while( successor->left != nullptr && successor->left != current ) {
        successor = successor->left;
      }
      if( successor->left == nullptr ) {
        successor->left = current;
        current = current->right;
      }
      else {
        successor->left = nullptr;
        if( ++cnt == k ) Kth = current;
        current = current->left;
      }
    }
  }
  return Kth->value;
}
