#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"

class List {
public:
    List();
    List(const Node*);
    List(const KeyType&);
    List (const List*);
    ~List();

    // Поиск указателя на узел первого вхождения элемента в список
    Node* find       (const KeyType&) const;

    // Вставить элемент в начало списка.
    void  push       (const KeyType&);

    // Вставить элемент после указанного узла.
    void  pushAfter  (const KeyType&, const KeyType&);

    // Вставить элемент до указанного узла.
    void  pushBefore (const KeyType&, const KeyType&);

    // Вставить элемент в конец
    void  pushEnd    (const KeyType&);

    // Удалить первый узел, содерщищий указанный ключ.
    void  remove     (const KeyType&);

    // Получить указатель на первый элемент списка.
    Node* getFirst   (void) const;
private:
    // Указатель на первый узел списка.
    Node* first_;
};

#endif