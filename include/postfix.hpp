#ifndef _POSTFIX_H_
#define _POSTFIX_H_
#include "stack.hpp"

#define _SPACE_ ' '

typedef double VariableType;

class Postfix {
private:
	int rightBr(void);
	void decreasePriority(int);
	int  priorietyOperator(const char)const;
	int  isOperator(const char)const;
	int  isOperand(const char)const;
	Stack<char> res_;
	Stack<char> operator_;
	Stack<VariableType> a;
	string str_;
public:
	Postfix();
	~Postfix();

	void procStr(void);
	void setString(const string&);
	VariableType calculate(void);
	void getValuesOfVariables(void);
};

Postfix::Postfix(){
	operator_ = new Stack<char>();
	res_ = new Stack<char>();
	a = new Stack<VariableType>();
}

Postfix::~Postfix(void){

}

int Postfix::rightBr(void){
	char j = operator_.pop();
	while(j != '('){
		res_.push(j);
		j =  operator_.pop();
	}
	j = operator_.pop();
	operator_.push(j);
	return priorietyOperator(j);
}

void Postfix::decreasePriority(int k){
	char j = operator_.pop();
	while( (k <= priorietyOperator(j)) && (!operator_.isEmpty() )){
		res_.push(j);
		j = operator_.pop();
	}
	if (priorietyOperator(j) < k)
		operator_.push(j);
	operator_.push(k);
}

void Postfix::procStr(void){
	if (str_.length() == 0){
		cout << "Enter the expression" << endl;
		cin >> str_;
	}
	int k = 0; // Текущий приоритет
	int m = 0; // Приоритет последнего элемента в operator_
	for (int i = 0; i < (int)str_.length(); i++){
		if (isOperand(str_[i])){
			res_.push(str_[i]);
		}
		else if (isOperator(str_[i])){
			
			if (str_[i] == ')'){
				m = rightBr();
				continue;
			}

			k = priorietyOperator(str_[i]);
			if (k < m){
				decreasePriority(k);
				m = k;
				continue;
			}
			m = k;

			operator_.push(str_[i]);
		} else {
			continue;
		}
	}
	while(!operator_.isEmpty())
		res_.push(operator_.pop());
}


void Postfix::setString(const string& str){
	str_ = str;
}
	
int Postfix::isOperator(const char key)const{
	switch (key)
	{
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 1;
		case '/':
			return 1;
		case '(':
			return 1;
		case ')':
			return 1;
		case '=':
			return 1;
		default:
			return 0;
	}
}
	
int Postfix::isOperand(const char key)const{
	if ((isOperator(key)) || (key == _SPACE_))
		return 0;
	return 1;
}

int Postfix::priorietyOperator(const char key)const{
	if (isOperator(key))
		switch (key)
		{
			case '+':
				return 2;
			case '-':
				return 2;
			case '*':
				return 3;
			case '/':
				return 3;
			case '(':
				return 1;
			case ')':
				return 1;
			case '=':
				return 0;
		}
    return -1;
}

VariableType Postfix::calculate(void){
	VariableType a = 0;
	return a;
}
	
void Postfix::getValuesOfVariables(void){

}

#endif