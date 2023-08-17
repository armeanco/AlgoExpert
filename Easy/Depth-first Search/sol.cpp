#include <vector>
#include <string>
class Node {
public:
  std::string name;
  std::vector<Node *> children;

  Node(std::string str) { name = str; }

  std::vector<std::string> depthFirstSearch(std::vector<std::string> *array) {
    array->push_back(this->name);
    for( const auto c : children ) {
      c->depthFirstSearch(array);
    }
    return *array;
  }

  Node *addChild(std::string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
