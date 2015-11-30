#include "list.h"

List::List()
{

}

List::List(const Node*)
{

}

List::List(const List*)
{

}

List::~List()
{

}

Node* List::find(const KeyType& key) const
{
    if (first_ == 0)
        throw("List doesn't exist");

    Node* node = first_;
    KeyType tmp = key;
    do {
        if (node->key_ == key)
            break;
        node = node->next_;
    } while (node != 0);

    if (node == 0)
    {
        delete node;
        throw("Node is not found");
    }

    return node;
}

void List::push(const KeyType& key)
{
    Node* node;
    try {
        node = new Node(key);
    }
    catch (...) {
        throw("No memory");
    }
    node->next_ = first_;
    first_ = node;
}

void List::pushAfter(const KeyType& nodeKey, const KeyType& key)
{
    Node* firstOccurrence;
    
    try {
        firstOccurrence = find(nodeKey);
    }
    catch (...) {
        pushEnd(key);
    }

    Node* tmp = firstOccurrence->next_;
    Node* node;
    try{
        node = new Node(key);
    }
    catch (...) {
        throw("No memory");
    }

    firstOccurrence->next_ = node;
    node->next_ = tmp;
}

void List::pushBefore(const KeyType& nodeKey, const KeyType& key)
{

}

void List::pushEnd(const KeyType& key)
{
    Node* node;
    try {
        node = new Node(key);
    }
    catch (...) {
        throw("No memory");
    }

    Node* first = first_;

    while (first->next_ != 0)
        first = first->next_;
        
    first->next_ = node;
}

void List::remove(const KeyType& key)
{
    
}

Node * List::getFirst(void) const
{
    return first_;
}
