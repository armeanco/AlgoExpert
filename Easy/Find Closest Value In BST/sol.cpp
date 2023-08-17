#include <cmath>
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target, int closest = 1e9) {
  if( tree == nullptr ) return closest;
  else {
    if(std::abs(tree->value - target ) < std::abs(closest - target)) {
      closest = tree->value;
    }
    if( target < tree->value ) {
      return findClosestValueInBst(tree->left, target, closest);
    } else {
      return findClosestValueInBst(tree->right, target, closest);
    }
  }
  return -1;
}
