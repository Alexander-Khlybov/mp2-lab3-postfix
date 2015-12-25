#include "list.hpp"

int main(void) {
    
    List<int> *list = new List<int>;
    cout << "initial" << endl;
    list->print();
    cout << "push" << endl;
    list->push(1);
    list->print();
    cout << "pushEnd" << endl;

    list->pushEnd(3);
    list->print();
    cout << "pushAfter" << endl;

    list->pushAfter(1, 2);
    list->print();

    cout << "pushBefore" << endl;
    list->pushBefore(3, 7);
    list->print();

    cout << "remove" << endl;
    list->remove(1);
    list->print();
    cout << endl << endl;

    return 0;}