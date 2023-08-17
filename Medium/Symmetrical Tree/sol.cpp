using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;

  BinaryTree(int value) { this->value = value; }

  static bool isMirror(BinaryTree* tree1, BinaryTree* tree2 ) {
    if( tree1 == nullptr && tree2 == nullptr ) return 1;
    if( tree1 && tree2 && tree1->value == tree2->value )
      return isMirror(tree1->left, tree2->right) && isMirror(tree1->right, tree2->left);
    return 0;
  }
};

bool symmetricalTree(BinaryTree* tree) {
  return BinaryTree::isMirror(tree, tree);
}
