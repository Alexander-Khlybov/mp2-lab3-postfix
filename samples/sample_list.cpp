#include "list.hpp"

int main(void) {
    
    List<int> *list = new List<int>;
    list->push(1);
    list->pushEnd(3);
    list->pushAfter(1, 2);
    Node<int>* first = list->getFirst();
    while (first != 0) {
        cout << first->key_ << " - ";
        first = first->next_;
    }
    list->remove(2);
    cout << endl << endl;
    first = list->getFirst();
    while (first != 0) {
        cout << first->key_ << " - ";
        first = first->next_;
    }
    return 0;}
