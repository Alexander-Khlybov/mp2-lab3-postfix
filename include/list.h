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

    // ����� ��������� �� ���� ������� ��������� �������� � ������.
    Node* find      (const KeyType&) const;

    // �������� ������� � ������ ������.
    int  push       (const KeyType&);

    // �������� ������� ����� ���������� ����.
    int  pushAfter  (const KeyType&, const KeyType&);

    // �������� ������� �� ���������� ����.
    int  pushBefore (const KeyType&, const KeyType&);

    // �������� ������� � �����
    int  pushEnd   (const KeyType&);

    // ������� ������ ����, ���������� ��������� ����.
    void  remove    (const KeyType&);

    // �������� ��������� �� ������ ������� ������.
    Node* getFirst  (void) const;
private:
    // ��������� �� ������ ���� ������.
    Node* first_;
};

#endif