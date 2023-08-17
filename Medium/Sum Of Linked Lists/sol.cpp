using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
 public:
  int value;
  LinkedList* next = nullptr;

  LinkedList(int value) { this->value = value; }

  static std::string traverse(LinkedList* one, LinkedList* two) {
    std::string a = "", b = "";
    while( one != nullptr ) {
      a += std::to_string(one->value);
      one = one->next;
    }
    while( two != nullptr ) {
      b += std::to_string(two->value);
      two = two->next;
    }
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int x = std::stoi(a), y = std::stoi(b), s = x + y;
    std::string p = std::to_string(s);
    std::reverse(p.begin(), p.end());
    return p;
  }
};

LinkedList* sumOfLinkedLists(
  LinkedList* linkedListOne, LinkedList* linkedListTwo
) {
  std::string res = LinkedList::traverse(linkedListOne, linkedListTwo);
  LinkedList* head = new LinkedList(static_cast<int>(res[0]-48));
  LinkedList* ptr = head;
  for( int i = 1; i < res.size(); ++i ) {
    ptr->next = new LinkedList(static_cast<int>(res[i]-48));
    ptr = ptr->next;
  }
  return head;
}
