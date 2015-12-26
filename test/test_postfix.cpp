#include "postfix.h"

#include <gtest.h>

TEST(Postfix, rewriteLineFromInfixToPostfix_works_properly){
	string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)*k";
	string str1 = "abc+d-*dfc-/kl+s/-k*+";
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