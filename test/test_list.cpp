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

TEST(List, can_push_key) {
    List<int>* list = new List<int>;
    ASSERT_NO_THROW(list->push(2));
}

TEST(List, push_key) {
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

TEST(List, copied_list_is_equal_to_source_one) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    List<int>* list1 = new List<int>(*list);
    EXPECT_EQ(*list, *list1);
}

TEST(List, can_find_key) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_NO_THROW(list->find(3));
}

TEST(List, find_return_pNode) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    EXPECT_EQ(list->getFirst()->next_, list->find(3));
}

TEST(List, throws_when_key_was_not_found) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_ANY_THROW(list->find(5));
}

TEST(List, can_push_key_after_findkey) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_NO_THROW(list->pushAfter(4, 5));
}

TEST(List, pushAfter_works_properly) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    list->pushAfter(4, 5);
    List<int>* list1 = new List<int>;
    list1->push(3);
    list1->push(5);
    list1->push(4);
    EXPECT_EQ(*list1, *list);
}

TEST(List, throws_when_findKey_does_not_exist_PA) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_ANY_THROW(list->pushAfter(7, 5));
}

TEST(List, can_push_key_at_the_end_of_list) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_NO_THROW(list->pushEnd(5));
}

TEST(List, pushEnd_works_properly) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    list->pushEnd(5);
    List<int>* list1 = new List<int>;
    list1->push(5);
    list1->push(3);
    list1->push(4);
    EXPECT_EQ(*list1, *list);
}

TEST(List, can_remove_node_by_key) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_NO_THROW(list->remove(3));
}

TEST(List, remove_works_properly) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(5);
    list->push(4);
    list->remove(5);
    List<int>* list1 = new List<int>;
    list1->push(3);
    list1->push(4);
    EXPECT_EQ(*list1, *list);
}

TEST(List, throws_when_findKey_does_not_exist_RM) {
    List<int>* list = new List<int>;
    list->push(3);
    list->push(4);
    ASSERT_ANY_THROW(list->remove(7));
}