#include "list.h"

List::List(void){
    first_ = 0;
}

List::List(const Node* node){
    first_ = new Node(node);
}

List::List(const KeyType& key){
    first_ = new Node(key);
}


List::List(const List* list){
    Node* tmp = list->first_;
    first_ = new Node(tmp->key_);
    Node* first = first_;
    tmp = tmp->next_;
    first = first->next_;
    while(tmp != 0){
        first = new Node(tmp->key_);
        tmp = tmp->next_;
        first = first->next_;
    }
}

List::~List(){
    delete first_;
}

Node* List::find(const KeyType& key) const{
    if (first_ == 0)
        throw("List doesn't exist");
      
    Node* node = first_;
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

int List::push(const KeyType& key){
    Node* node;
    try {
        node = new Node(key);
    }
    catch (...) {
        return 1;
    }
    
    node->next_ = first_;
    first_ = node;

    return 0;
}

int List::pushAfter(const KeyType& findKey, const KeyType& key){
    Node* firstOccurrence;
    
    try {
        firstOccurrence = find(findKey);
    }
    catch (...) {
        return pushEnd(key);
    }

    Node* tmp = firstOccurrence->next_;

    Node* node;
    try{
        node = new Node(key);
    } catch (...) {
        return 1;
    }

    firstOccurrence->next_ = node;
    node->next_ = tmp;

    return 0;
}

int List::pushBefore(const KeyType& findKey, const KeyType& key){
    if (first_ == 0)
        throw("List doesn't exist")

    if (first_->key_ == key)
        return push(key);

    if (first_->next_ == 0)
        throw("findKey wasn't found.");

    Node* prewNode = first_;
    Node* node = first_->next_;

    while ( (node->next_ != 0) && (node->key_ != key) ) {
        prewNode = node;
        node = prewNode->next_;
    } 

    if ( (node->next_ == 0) && (node->key_ != key) )
        throw("findKey wasn't found");

    Node *tmp;
    try{
        tmp = new Node(key);
    } catch (...) {
        return 1;
    }

    prewNode->next_ = tmp;
    tmp->next_ = node;

    return 0;
}

int List::pushEnd(const KeyType& key){
    if (first_ == 0)
        return push(key);

    Node* node;
    try {
        node = new Node(key);
    } catch (...) {
        return 1;
    }

    Node* first = first_;

    while (first->next_ != 0)
        first = first->next_;
        
    first->next_ = node;

    return 0;
}

void List::remove(const KeyType& findKey){
    if (first_ == 0)
        throw("List can't be removed");

    first_ = first_->next_;
}

Node * List::getFirst(void) const{
    return first_;
}
