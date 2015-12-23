#include "postfix.h"

#include <gtest.h>

TEST(Postfix, can_set_string) {
    string s = "a + b";
    Postfix p;
    ASSERT_NO_THROW(p.setString(s));
}

TEST(Postfix, setString_returns_1_when_operand_operand) {
    string s = "ab";
    Postfix p;
    EXPECT_EQ(1, p.setString(s));
}

TEST(Postfix, setString_returns_1_when_operator_operator_) {
    string s = "**";
    Postfix p;
    EXPECT_EQ(1, p.setString(s));
    s = "*/";
    EXPECT_EQ(1, p.setString(s));
    s = "*+";
    EXPECT_EQ(1, p.setString(s));
    s = "*-";
    EXPECT_EQ(1, p.setString(s));
    s = "*)";
    EXPECT_EQ(1, p.setString(s));

    s = "/*";
    EXPECT_EQ(1, p.setString(s));
    s = "//";
    EXPECT_EQ(1, p.setString(s));
    s = "/+";
    EXPECT_EQ(1, p.setString(s));
    s = "/-";
    EXPECT_EQ(1, p.setString(s));
    s = "/)";
    EXPECT_EQ(1, p.setString(s));

    s = "+*";
    EXPECT_EQ(1, p.setString(s));
    s = "-*";
    EXPECT_EQ(1, p.setString(s));
    s = "(*";
    EXPECT_EQ(1, p.setString(s));
    s = "-+";
    EXPECT_EQ(1, p.setString(s));
    s = "+-";
    EXPECT_EQ(1, p.setString(s));

    s = "+";
    EXPECT_EQ(1, p.setString(s));
    s = "*";
    EXPECT_EQ(1, p.setString(s));
    s = "/";
    EXPECT_EQ(1, p.setString(s));
    s = ")";
    EXPECT_EQ(1, p.setString(s));
}

TEST(Postfix, can_procStr) {
    string s = "a + b";
    Postfix p;
    p.setString(s);

    ASSERT_NO_THROW(p.procStr());
}

TEST(Postfix, calculate) {
    string s = "a + b";
    Postfix p;
    p.setString(s);
    p.procStr();
    p.calculate();

    ADD_FAILURE();
}