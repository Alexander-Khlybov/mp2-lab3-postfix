#include "stack.h"

Stack::Stack(){
	list_ = new List();
}

Stack::Stack(const Stack* stack){
	list_ = new List(stack->list_);
}

Stack::~Stack(void){
	delete list_;
}

int Stack::isFull(void) const{
	Node *node;
	try{
		node = new Node();
	} catch (...) {
		return 1;
	}
	delete node;
	return 0;
}

int Stack::isEmpty(void) const{
	return (list_->getFirst() == 0);
}

void Stack::push(const KeyType& key){
	if (isFull())
		throw("Stack is full");
	list_->push(key);
}

KeyType Stack::pop(void){
	if (isEmpty())
		throw("Stack is empty");
	KeyType tmp = list_->getFirst()->key_;
	list_->remove(tmp);
	return tmp;
}

