class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

  BST &insert(int val) {
    if( val < value ) {
      if( left == nullptr ) {
        left = new BST( val );
      }
      else left->insert( val );
    }
    if( val >= value ) {
      if( right == nullptr ) {
        right = new BST( val );
      } else right->insert( val );
    }
    return *this;
  }

  bool contains(int val) {
    BST* node = this;
    while( node != nullptr ) {
      if( node->value == val ) return true;
      else if( node->value < val ) node = node->right;
      else node = node->left;
    }
    return false;
  }

  int successor(BST * root) {
    root = root->right;
    while (root->left != nullptr) root = root->left;
    return root->value;
  }

  int predecessor(BST * root) {
    root = root->left;
    while (root->right != nullptr) root = root->right;
    return root->value;
  }
 
  BST * deleteNode(BST * root, int key) {
    if (root == nullptr) return nullptr;
    if (key > root->value) root->right = deleteNode(root->right, key);
    else if (key < root->value) root->left = deleteNode(root->left, key);
    else {
      if (root->left == nullptr && root->right == nullptr) root = nullptr;
      else if (root->right != nullptr) {
        root->value = successor(root);
        root->right = deleteNode(root->right, root->value);
      } else {
        root->value = predecessor(root);
        root->left = deleteNode(root->left, root->value);
      }
    }
    return root;
  }

  BST &remove(int val) {
    BST* node = this;
    return *deleteNode(node, val);
  }
};
