#ifndef _LIST_H_
#define _LIST_H_
#include "node.h"

class List {
public:
    List();
    List(const Node*);
    List (const List*);
    ~List();

    // ����� ��������� �� ���� ������� ��������� �������� � ������
    Node* find       (const KeyType& key) const;

    // �������� ������� � ������ ������.
    void  push       (const KeyType& key);

    // �������� ������� ����� ���������� ����.
    void  pushAfter  (Node* node, const KeyType& key);

    // �������� ������� �� ���������� ����.
    void  pushBefore (Node* node, const KeyType& key);

    // �������� ������� � �����
    void  pushEnd    (const KeyType& key);

    // ������� ������ ����, ���������� ��������� ����.
    void  remove     (const KeyType& key);

    // �������� ��������� �� ������ ������� ������.
    Node* getFirst   (void);
private:
    // ��������� �� ������ ���� ������.
    Node* node_;
};

#endif