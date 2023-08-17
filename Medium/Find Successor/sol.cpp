using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
 public:
  int value;
  BinaryTree* left = nullptr;
  BinaryTree* right = nullptr;
  BinaryTree* parent = nullptr;

  BinaryTree(int value) { this->value = value; }

  static BinaryTree* minVal(BinaryTree* node) {
    BinaryTree* t = node;

    while( t->left != nullptr ) {
      t = t->left;
    }
    return t;
  }

  static BinaryTree* inOrder(BinaryTree* tree, BinaryTree* node) {
    if( node->right != nullptr )
      return minVal(node->right);

    BinaryTree* nxt = node->parent;
    while( nxt != nullptr && node == nxt->right) {
      node = nxt;
      nxt = nxt->parent;
    }
    return nxt;
  }
};

BinaryTree* findSuccessor(BinaryTree* tree, BinaryTree* node) {
  return BinaryTree::inOrder(tree, node);
}
