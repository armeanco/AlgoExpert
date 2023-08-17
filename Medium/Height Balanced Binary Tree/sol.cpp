using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }

  static int height(BinaryTree* tree) {
    if( tree == nullptr ) return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
  }
};

bool heightBalancedBinaryTree(BinaryTree* tree) {
  if( tree == nullptr ) return 1;
  int lh = BinaryTree::height(tree->left), rh = BinaryTree::height(tree->right);
  return std::abs(lh - rh) <= 1 && heightBalancedBinaryTree(tree->left) && heightBalancedBinaryTree(tree->right);
}
