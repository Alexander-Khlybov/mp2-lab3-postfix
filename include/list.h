#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"

class List {
public:
    List();
    List(const Node*);
    List (const List*);
    ~List();

    // Поиск указателя на узел первого вхождения элемента в список
    Node* find       (const KeyType& key) const;

    // Вставить элемент в начало списка.
    void  push       (const KeyType& key);

    // Вставить элемент после указанного узла.
    void  pushAfter  (Node* node, const KeyType& key);

    // Вставить элемент до указанного узла.
    void  pushBefore (Node* node, const KeyType& key);

    // Вставить элемент в конец
    void  pushEnd    (const KeyType& key);

    // Удалить первый узел, содерщищий указанный ключ.
    void  remove     (const KeyType& key);

    // Получить указатель на первый элемент списка.
    Node* getFirst   (void);
private:
    // Указатель на первый узел списка.
    Node* node_;
};

#endif