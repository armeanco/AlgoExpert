using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  static int height(BinaryTree* tree, int& ans) {
    if( tree == nullptr ) return 0;

    int lh = height(tree->left, ans), rh = height(tree->right, ans);

    ans = std::max(ans, lh + rh + 1);

    return 1 + std::max(lh, rh);
  }
};

int binaryTreeDiameter(BinaryTree* tree) {
  if( tree == nullptr ) return 0;
  int ans = -1e6;
  BinaryTree::height(tree, ans);
  return ans - 1;
}
