#ifndef _LIST_H_
#define _LIST_H_
#include "node.hpp"
#include "excp.h"

template <class KeyType>
class List { 
public:
    List(void);
    List (const List<KeyType>&);
    ~List(void);

// перегрузка сравнения на равенство
    int operator== (const List&)const;

// перегрузка сравнения на неравенство
    int operator!= (const List&)const;

// поиск адреса узла, содержащего элемент key
    Node<KeyType>* find      (const KeyType&) const;

// добавление элемента с ключом key к началу списка
    void  push       (const KeyType&);

// добавление элемента с ключом key перед элементом с ключом findKey
    void  pushBefore  (const KeyType&, const KeyType&);

// добавление элемента с ключом key после элемента с ключом findkey
    void  pushAfter  (const KeyType&, const KeyType&);

// добавление элемента с ключом key в конец списка
    void  pushEnd   (const KeyType&);

// удаление элемента с ключом key
    void  remove    (const KeyType&);

// получение указатеря на первый узел списка
    Node<KeyType>* getFirst  (void) const;

// печать списка
    void print(void)const;

private:
// указатель на первое звено списка
    Node<KeyType>* first_;
};

// конструктор по умолчанию
template <class KeyType>
List<KeyType>::List(void){
    first_ = 0;
}

// конструктор копирования
template <class KeyType>
List<KeyType>::List(const List<KeyType>& list){
    
    first_ = 0;
    Node<KeyType>* tmp = list.first_;
    while (tmp != 0){
        pushEnd(tmp->key_);
        tmp = tmp->next_;
    }
}

// деструктор
template <class KeyType>
List<KeyType>::~List(){
    Node<KeyType> *tmp = first_;
    while (first_ != 0) {
        first_ = first_->next_;
        delete tmp;
        tmp = first_;
    }
}

// перегрузка сравнения на равенство
template <class KeyType>
int List<KeyType>::operator== (const List& list)const{
    Node<KeyType>* first1 = first_;
    Node<KeyType>* first2 = list.first_;
    while ((first1 != 0) && (first2 != 0)){
        if(first1->key_ != first2->key_)
            return 0;
        first1 = first1->next_;
        first2 = first2->next_;
    }

    if (first1 != first2)
        return 0;
    return 1;
}

// перегрузка сравнения на неравенство
template <class KeyType>
int List<KeyType>::operator!= (const List& list)const{
    return !(*this == list);
}

// поиск адреса узла, содержащего элемент key
template <class KeyType>
Node<KeyType>* List<KeyType>::find(const KeyType& key) const{
    if (first_ == 0)
        throw myExcp("List doesn't exist");
      
    Node<KeyType>* node = first_;
    do {
        if (node->key_ == key)
            break;
        node = node->next_;
    } while (node != 0);

    if (node == 0){
        delete node;
        throw myExcp("Node is not found");
    }

    return node;
}

// добавление элемента с ключом key к началу списка
template <class KeyType>
void List<KeyType>::push(const KeyType& key){
    Node<KeyType>* node;
    try {
        node = new Node<KeyType>(key);
    }
    catch (...) {
        throw myExcp("No memory.");
    }
    
    node->next_ = first_;
    first_ = node;
}

// добавление элемента с ключом key перед элементом с ключом findKey
template <class KeyType>
void List<KeyType>::pushBefore  (const KeyType& findKey, const KeyType& key){
    Node<KeyType>* findNode = find(findKey);

    if (first_ == findNode) {
        push(key);
        return;
    }

    Node<KeyType>* previousNode = first_;
    while (previousNode->next_ != findNode)
        previousNode = previousNode->next_;

    Node<KeyType>* temporaryAddress = previousNode->next_;
    Node<KeyType>* tmpNodeKey = new Node<KeyType>(key);
    previousNode->next_ = tmpNodeKey;
    tmpNodeKey->next_ = temporaryAddress;
}

// добавление элемента с ключом key после элемента с ключом findkey
template <class KeyType>
void List<KeyType>::pushAfter(const KeyType& findKey, const KeyType& key){
    Node<KeyType>* firstOccurrence;
    
    firstOccurrence = find(findKey);

    Node<KeyType>* tmp = firstOccurrence->next_;

    Node<KeyType>* node;
    try{
        node = new Node<KeyType>(key);
    } catch (...) {
        throw myExcp("No memory.");
    }

    firstOccurrence->next_ = node;
    node->next_ = tmp;
}

// добавление элемента с ключом key в конец списка
template <class KeyType>
void List<KeyType>::pushEnd(const KeyType& key){
    if (first_ == 0) {
        push(key);
        return;
    }

    Node<KeyType>* node;
    try {
        node = new Node<KeyType>(key);
    } catch (...) {
        throw myExcp("No memory.");
    }

    Node<KeyType>* first = first_;

    while (first->next_ != 0)
        first = first->next_;
        
    first->next_ = node;
}

// удаление элемента с ключом key
template <class KeyType>
void List<KeyType>::remove(const KeyType& findKey){
    Node<KeyType>* findNode = find(findKey);

    if (first_ == findNode) {
        first_ = first_->next_;
        return;
    }

    Node<KeyType>* first = first_;
    while (first->next_ != findNode)
        first = first->next_;
    first->next_ = findNode->next_;
    delete findNode;
}

// получение указатеря на первый узел списка
template <class KeyType>
Node<KeyType>* List<KeyType>::getFirst(void) const{
    return first_;
}

template <class KeyType>
void List<KeyType>::print(void)const {
    Node<KeyType>* first = first_;
    while (first != 0) {
        cout << first->key_ << " -> ";
        first = first->next_;
    }
    cout << "-|///" << endl;
}


#endif