// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  LinkedList *p1, *p2, *p3;
  p1 = linkedList;
  while( p1 != nullptr && p1->next != nullptr ) {
    p2 = p1;
    while( p2->next != nullptr ) {
      if( p1->value == p2->next->value ) {
        p3 = p2->next;
        p2->next = p2->next->next;
        free(p3);
      }
      else {
          p2 = p2->next;
      }
    }
    p1 = p1->next;
  }
  return linkedList;
}
