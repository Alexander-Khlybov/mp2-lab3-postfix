#include "stack.hpp"

int main(void) {
    
    Stack<int>* s = new Stack<int>;
    cout << "isEmpty" << endl;
    cout << s->isEmpty() << endl;

    int i = 0;
    for (i; i < 10; i++)
        s->push(i);

    cout << "Initial" << endl;
    s->print();

    cout << "pop" << endl;
    s->pop();
    s->print();

    cout << "push(10)" << endl;
    s->push(i);
    s->print();
    
    return 0;}
