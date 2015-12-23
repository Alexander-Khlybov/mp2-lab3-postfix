#include "stack.hpp"

#include <gtest.h>

TEST(Stack, can_create_stack) {
    Stack<int>* s;
    ASSERT_NO_THROW(s = new Stack<int>);
}

TEST(Stack, created_stack_is_empty) {
    Stack<int>* s = new Stack<int>;
    EXPECT_EQ(1, s->isEmpty());
}

TEST(Stack, throws_when_pop_from_empty) {
    Stack<int>* s = new Stack<int>;
    ASSERT_ANY_THROW(s->pop());
}

TEST(Stack, can_push) {
    Stack<int>* s = new Stack<int>;
    ASSERT_NO_THROW(s->push(1));
}

TEST(Stack, can_pop) {
    Stack<int>* s = new Stack<int>;
    s->push(3);
    int tmp;
    ASSERT_NO_THROW(tmp = s->pop());
    EXPECT_EQ(3, tmp);
}

TEST(Stack, compare_equal_stacks_return_true) {
    Stack<int> s;
    Stack<int> s1;
    s1.push(3);
    s.push(3);
    s1.push(4);
    s.push(4);
    EXPECT_EQ(s, s1);
}

TEST(Stack, compare_non_equal_stacks_return_false) {
    Stack<int>* s = new Stack<int>;
    Stack<int>* s1 = new Stack<int>;
    s1->push(3);
    s->push(3);
    s1->push(4);
    s->push(2);
    EXPECT_NE(*s, *s1);
}

TEST(Stack, can_copy_stack) {
    Stack<int>* s = new Stack<int>;
    s->push(3);
    s->push(2);
    ASSERT_NO_THROW(Stack<int>* s1 = new Stack<int>(*s));
}

TEST(Stack, copied_stack_is_equal_to_source_one) {
    Stack<int>* s = new Stack<int>;
    s->push(3);
    s->push(2);
    Stack<int>* s1 = new Stack<int>(*s);
    EXPECT_EQ(*s, *s1);
}