#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"

class List {
public:
    List(void);
    List(const Node*);
    List(const KeyType&);
    List (const List*);
    ~List(void);

    // Поиск указателя на узел первого вхождения элемента в список.
    Node* find      (const KeyType&) const;

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
    Node* getFirst  (void) const;
private:
    // Указатель на первый узел списка.
    Node* first_;
};

#endif