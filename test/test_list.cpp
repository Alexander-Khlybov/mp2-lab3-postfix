#include "list.hpp"

#include <gtest.h>

TEST(Node, can_create_node) {
    Node<int>* node;
    ASSERT_NO_THROW(node = new Node<int>);
}

TEST(Node, created_node_by_key) {
    Node<int>* node;
    ASSERT_NO_THROW(node = new Node<int>(2));
}

TEST(Node, created_node_by_key_is_equal_to_key) {
    Node<int>* node = new Node<int>(2);
    EXPECT_EQ(2, node->key_);
    EXPECT_EQ(0, node->next_);
}
/*
List(const List<KeyType>&);
Node<KeyType>* find(const KeyType&) const;
int  pushAfter(const KeyType&, const KeyType&);
int  pushBefore(const KeyType&, const KeyType&);
int  pushEnd(const KeyType&);
void  remove(const KeyType&);
*/

TEST(List, can_create_list) {
    List<int>* list;
    ASSERT_NO_THROW(list = new List<int>);
}

TEST(List, can_get_pointer_on_first_node) {
    List<int>* list = new List<int>;
    ASSERT_NO_THROW(list->getFirst());
}

TEST(List, created_list_is_empty) {
    List<int>* list = new List<int>;
    EXPECT_EQ(0, list->getFirst());
}

TEST(Lit, can_push_key) {
    List<int>* list = new List<int>;
    ASSERT_NO_THROW(list->push(2));
}

TEST(Lit, push_key) {
    List<int>* list = new List<int>;
    list->push(2);
    list->push(3);
    EXPECT_EQ(3, list->getFirst()->key_);
}

TEST(List, compare_equal_lists_return_true) {
    List<int>* list = new List<int>;
    List<int>* list1 = new List<int>;

    list->push(2);
    list1->push(2);
    list->push(3);
    list1->push(3);
    EXPECT_EQ(*list1, *list);
}

TEST(List, compare_non_equal_lists_return_false) {
    List<int>* list = new List<int>;
    List<int>* list1 = new List<int>;

    list->push(2);
    list1->push(1);
    list->push(3);
    list1->push(3);
    EXPECT_NE(*list1, *list);
}

TEST(List, can_copy_list) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_NO_THROW(List<int>* list1 = new List<int>(*list));
}

TEST(List, copied_list_is_equal_to_soutce_one) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    List<int>* list1 = new List<int>(*list);
    EXPECT_EQ(*list, *list1);
}