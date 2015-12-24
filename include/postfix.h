#ifndef _POSTFIX_H_
#define _POSTFIX_H_
#include "stack.hpp"
#include <map>

#define _SPACE_ ' '

typedef double VariableType;

class Postfix {
protected:
    int isOperator(char);
	void checkBrackets(const string&)const;
    int checkingLine(const string&)const;
public:
	string rewriteLineFromInfixToPostfix(const string&)const;
	VariableType calculate(const string&, map<char, VariableType>);
};
#endif