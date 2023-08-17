using namespace std;

class BST {
 public:
  int value;
  BST* left;
  BST* right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }

  static BST* precompute(std::vector<int> &array, int start, int end) {
    if( start > end ) return nullptr;
    int middle = ( start + end ) / 2;
    BST* node = new BST(array[middle]);
    node->left = precompute(array, start, middle - 1);
    node->right = precompute(array, middle + 1, end);
    return node;
  }
};

BST* minHeightBst(vector<int> array) {
  return BST::precompute(array, 0, array.size() - 1);
}
