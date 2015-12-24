#include "postfix.h"

#include <gtest.h>

TEST(Postfix, rewriteLineFromInfixToPostfix_works_properly){
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)";
	string str1 = "abcd-+*dfc-/kl+s/-+";
	Postfix p;
	EXPECT_EQ(str1, p.rewriteLineFromInfixToPostfix(str));
}

TEST(Postfix, calculate){
	Postfix p;
    string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)";

    map<char, VariableType> m;
    m['a'] = 1;
    m['b'] = 5;
    m['c'] = 3;
    m['d'] = 4;
    m['f'] = 5;
    m['k'] = 10;
    m['l'] = 15;
    m['s'] = 5;
    EXPECT_EQ(1, p.calculate(p.rewriteLineFromInfixToPostfix(str), m));
}