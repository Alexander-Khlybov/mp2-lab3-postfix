#ifndef _STACK_H_
#define _STACK_H_
#include "list.hpp"

template <class KeyType>
class Stack {
public:
	Stack(void);
	Stack(const Stack<KeyType>&);
	~Stack(void);

    int operator== (const Stack&)const;
    int operator!= (const Stack&)const;

	// Проверка на полноту.
	int isFull(void) const;

	// Проверка на пустоту.
	int isEmpty(void) const;

	// Положить элемент в стек.
	void push(const KeyType&);
	
	// Взять элемент из стека.
	KeyType pop(void);

    KeyType peek(void);

    // Печать стека
    void print(void)const;
private:
	List<KeyType>* list_;
};


template <class KeyType>
Stack<KeyType>::Stack(){
	list_ = new List<KeyType>();
}

template <class KeyType>
Stack<KeyType>::Stack(const Stack<KeyType>& stack){
	list_ = new List<KeyType>(*(stack.list_));
}

template <class KeyType>
Stack<KeyType>::~Stack(void){
	delete list_;
}

template <class KeyType>
int Stack<KeyType>::operator== (const Stack& stack)const{
	return (*list_ == *(stack.list_));
}

template <class KeyType>
int Stack<KeyType>::operator!= (const Stack& stack)const{
	return (*list_ != *(stack.list_));
}

template <class KeyType>
int Stack<KeyType>::isFull(void) const{
	Node<KeyType> *node;
	try{
		node = new Node<KeyType>;
	} catch (...) {
		return 1;
	}
	delete node;
	return 0;
}

template <class KeyType>
int Stack<KeyType>::isEmpty(void) const{
	return (list_->getFirst() == 0);
}

template <class KeyType>
void Stack<KeyType>::push(const KeyType& key){
	if (isFull())
		throw exception("Stack is full");
	list_->push(key);
}

template <class KeyType>
KeyType Stack<KeyType>::pop(void){
	if (isEmpty())
		throw exception("Stack is empty");
	KeyType tmp = list_->getFirst()->key_;
	list_->remove(tmp);
	return tmp;
}

template <class KeyType>
void Stack<KeyType>::print(void)const {
    Stack<KeyType>* s = new Stack<KeyType>(*this);

    while (!(s->isEmpty()))
        cout << s->pop() << endl;

}
template <class KeyType>
KeyType Stack<KeyType>::peek(void) {
    if (list_->getFirst() == 0)
    	throw exception("Stack is empty."); 
        return list_->getFirst()->key_;
    
}


#endif