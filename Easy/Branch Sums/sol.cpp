#include <vector>
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

void calculate(BinaryTree* root, int run, std::vector<int> &sum) {
  if( root == nullptr ) return;
  int running = run + root->value;
  if( root->right == nullptr && root->left == nullptr ) sum.push_back(running);
  calculate(root->left, running, sum);
  calculate(root->right, running, sum);
}

std::vector<int> branchSums(BinaryTree *root) {
  std::vector<int> sequence;
  calculate(root, 0, sequence);
  return sequence;
}
