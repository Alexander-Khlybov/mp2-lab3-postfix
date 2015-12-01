#ifndef _STACK_H_
#define _STACK_H_
#include "list.h"

class Stack {
public:
	Stack(void);
	Stack(const Stack*);
	~Stack(void);

	// Проверка на полноту.
	int isFull(void) const;

	// Проверка на пустоту.
	int isEmpty(void) const;

	// Положить элемент в стек.
	void push(const KeyType&);
	
	// Взять элемент из стека.
	KeyType pop(void);
private:
	List* list_;
};

#endif