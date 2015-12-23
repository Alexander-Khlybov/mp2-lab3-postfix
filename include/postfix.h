#ifndef _POSTFIX_H_
#define _POSTFIX_H_
#include "stack.hpp"

#define _SPACE_ ' '

typedef double VariableType;

class Postfix {
private:
	Stack<char>* res_;
	Stack<char>* operator_;
	Stack<VariableType>* expResult_;
	string str_;
    string resStr_;
	int op;

protected:
	int rightBr(void);
	void decreasePriority(int);
	int  priorietyOperator(const char)const;
	int  isOperator(const char)const;
	int  isOperand(const char)const;
	int checkingLine(void)const;

public:
	Postfix(void);
	~Postfix(void);

	void procStr(void);
	void setString(const string&);
	void printPostfix(void);
	VariableType calculate(void);
};
#endif