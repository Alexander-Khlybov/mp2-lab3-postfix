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

    // ����� ��������� �� ���� ������� ��������� �������� � ������
    Node* find       (const KeyType&) const;

    // �������� ������� � ������ ������.
    void  push       (const KeyType&);

    // �������� ������� ����� ���������� ����.
    void  pushAfter  (const KeyType&, const KeyType&);

    // �������� ������� �� ���������� ����.
    void  pushBefore (const KeyType&, const KeyType&);

    // �������� ������� � �����
    void  pushEnd    (const KeyType&);

    // ������� ������ ����, ���������� ��������� ����.
    void  remove     (const KeyType&);

    // �������� ��������� �� ������ ������� ������.
    Node* getFirst   (void) const;
private:
    // ��������� �� ������ ���� ������.
    Node* first_;
};

#endif