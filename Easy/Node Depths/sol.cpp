using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int calculate(BinaryTree* root, int cnt) {
  if( root == nullptr ) return 0;
  return cnt + calculate(root->left, cnt + 1) + calculate(root->right, cnt + 1);
}

int nodeDepths(BinaryTree *root) {
  int cnt = 0;
  return calculate(root, cnt);
}
