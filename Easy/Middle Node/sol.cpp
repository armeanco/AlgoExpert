using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *middleNode(LinkedList *linkedList) {
  LinkedList *node = linkedList;
  LinkedList *itr = linkedList;
  LinkedList *target = nullptr;
  LinkedList *get = linkedList;
  int cnt = 0;
  while(node != nullptr) {
    node = node->next;
    cnt++;
  }
  if( cnt % 2 != 0 ) {
    if( cnt > 1) { cnt /=2; }
    while( itr != nullptr ) {
      cnt--;
      itr = itr->next;
      if( cnt == 0 ) target = itr;
    }
  }
  return cnt == 0 ? get : target;
}
