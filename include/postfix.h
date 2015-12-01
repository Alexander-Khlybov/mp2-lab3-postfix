#ifndef _POSTFIX_H_
#define _POSTFIX_H_
#include "stack.h"

#define _SPACE_ ' '

typedef double VariableType;

class Postfix {

private:
	int rightBr(void);
	void decreasePriority(int);
	int  priorietyOperator(const char)const;
	int  isOperator(const char)const;
	int  isOperand(const char)const;
	Stack res_;
	Stack operator_;
	string str_ = '0';
public:
	Postfix();
	~Postfix();

	void procStr(void);
	void setString(const string&);
	VariableType calculate(void);
	void getValuesOfVariables(void);
};


#endif