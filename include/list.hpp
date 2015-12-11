#ifndef _LIST_H_
#define _LIST_H_
#include "node.hpp"

template <class KeyType>
class List { 
public:
    List(void);
    List(const Node<KeyType>*);
    List(const KeyType&);
    List (const List<KeyType>*);
    ~List(void);

    // Поиск указателя на узел первого вхождения элемента в список.
    Node<KeyType>* find      (const KeyType&) const;

    // Вставить элемент в начало списка.
    int  push       (const KeyType&);

    // Вставить элемент после указанного узла.
    int  pushAfter  (const KeyType&, const KeyType&);

    // Вставить элемент до указанного узла.
    int  pushBefore (const KeyType&, const KeyType&);

    // Вставить элемент в конец
    int  pushEnd   (const KeyType&);

    // Удалить первый узел, содерщищий указанный ключ.
    void  remove    (const KeyType&);

    // Получить указатель на первый элемент списка.
    Node<KeyType>* getFirst  (void) const;
private:
    // Указатель на первый узел списка.
    Node<KeyType>* first_;
};

template <class KeyType>
List<KeyType>::List(void){
    first_ = 0;
}

template <class KeyType>
List<KeyType>::List(const Node<KeyType>* node){
    first_ = new Node<KeyType>(node);
}

template <class KeyType>
List<KeyType>::List(const KeyType& key){
    first_ = new Node<KeyType>(key);
}


template <class KeyType>
List<KeyType>::List(const List<KeyType>* list){
    Node<KeyType>* tmp = list->first_;
    first_ = new Node<KeyType>(tmp->key_);
    Node<KeyType>* first = first_;
    tmp = tmp->next_;
    first = first->next_;
    while(tmp != 0){
        first = new Node<KeyType>(tmp->key_);
        tmp = tmp->next_;
        first = first->next_;
    }
}

template <class KeyType>
List<KeyType>::~List(){
    delete first_;
}

template <class KeyType>
Node<KeyType>* List<KeyType>::find(const KeyType& key) const{
    if (first_ == 0)
        throw("List doesn't exist");
      
    Node<KeyType>* node = first_;
    KeyType tmp = key;
    do {
        if (node->key_ == key)
            break;
        node = node->next_;
    } while (node != 0);

    if (node == 0){
        delete node;
        throw("Node is not found");
    }

    return node;
}

template <class KeyType>
int List<KeyType>::push(const KeyType& key){
    Node<KeyType>* node;
    try {
        node = new Node<KeyType>(key);
    }
    catch (...) {
        return 1;
    }
    
    node->next_ = first_;
    first_ = node;

    return 0;
}

template <class KeyType>
int List<KeyType>::pushAfter(const KeyType& findKey, const KeyType& key){
    Node<KeyType>* firstOccurrence;
    
    try {
        firstOccurrence = find(findKey);
    }
    catch (...) {
        return pushEnd(key);
    }

    Node<KeyType>* tmp = firstOccurrence->next_;

    Node<KeyType>* node;
    try{
        node = new Node<KeyType>(key);
    } catch (...) {
        return 1;
    }

    firstOccurrence->next_ = node;
    node->next_ = tmp;

    return 0;
}

template <class KeyType>
int List<KeyType>::pushBefore(const KeyType& findKey, const KeyType& key){
    if (first_ == 0)
        throw("List doesn't exist");

    if (first_->key_ == key)
        return push(key);

    if (first_->next_ == 0)
        throw("findKey wasn't found.");

    Node<KeyType>* prewNode = first_;
    Node<KeyType>* node = first_->next_;

    while ( (node->next_ != 0) && (node->key_ != key) ) {
        prewNode = node;
        node = prewNode->next_;
    } 

    if ( (node->next_ == 0) && (node->key_ != key) )
        throw("findKey wasn't found");

    Node<KeyType> *tmp;
    try{
        tmp = new Node<KeyType>(key);
    } catch (...) {
        return 1;
    }

    prewNode->next_ = tmp;
    tmp->next_ = node;

    return 0;
}

template <class KeyType>
int List<KeyType>::pushEnd(const KeyType& key){
    if (first_ == 0)
        return push(key);

    Node<KeyType>* node;
    try {
        node = new Node<KeyType>(key);
    } catch (...) {
        return 1;
    }

    Node<KeyType>* first = first_;

    while (first->next_ != 0)
        first = first->next_;
        
    first->next_ = node;

    return 0;
}

template <class KeyType>
void List<KeyType>::remove(const KeyType& findKey){
    if (first_ == 0)
        throw("List can't be removed");

    first_ = first_->next_;
}

template <class KeyType>
Node<KeyType> * List<KeyType>::getFirst(void) const{
    return first_;
}

#endif