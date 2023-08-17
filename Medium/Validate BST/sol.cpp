class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int val);
  BST& insert(int val);

  int minVal(BST* tree) {
    if( tree == nullptr ) return 1e9;
    int val = tree->value;
    int lMax = minVal(tree->left), rMax = minVal(tree->right);
    return std::min(val, std::min(lMax, rMax));
  }

  int maxVal(BST* tree) {
    if( tree == nullptr ) return -1e9;
    int val = tree->value;
    int lMax = maxVal(tree->left), rMax = maxVal(tree->right);
    return std::max(val, std::max(lMax, rMax));
  }
};

int validate(BST* tree) {
    if( tree == nullptr ) return 1;
    if( tree->left != nullptr && tree->maxVal(tree->left) >= tree->value ) return 0;
    if( tree->right != nullptr && tree->minVal(tree->right) < tree->value ) return 0;
    if( !validate(tree->left) || !validate(tree->right) ) return 0;
    return 1;
}

bool validateBst(BST* tree) {
  return validate(tree);
}
