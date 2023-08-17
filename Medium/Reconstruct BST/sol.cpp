// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }

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
};

BST *reconstructBst(vector<int> preOrderTraversalValues) {
  BST *root = new BST(preOrderTraversalValues[0]);
  for( std::size_t i = 1; i < preOrderTraversalValues.size(); ++i ) root->insert(preOrderTraversalValues[i]);
  return root;
}
