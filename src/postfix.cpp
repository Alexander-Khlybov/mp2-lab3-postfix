#include "postfix.h"

Postfix::Postfix(){
	opertor_ = new Stack();
	res_ = new Stack();
}
	
Postfix::~Postfix(void){

}

int rightBr(void){
	KeyType j = operator_.pop();
	while(j != '('){
		res_.push(j);
		j =  operator_.pop();
	}
	j = operator_.pop();
	operator_.push(j);
	return priorietyOperator(j);
}

void decreasePriority(int k){
	KeyType j = operator_.pop();
	while( (k <= priorietyOperator(j)) && (!operator_.isEmpty() ){
		res_.push(j);
		j = operator_.pop();
	}
	if (priorietyOperator(j) < k)
		operator_.push(j);
	operator_.push(k);
}

void procStr(void){
	if (str_ == "0"){
		cout << "Enter the expression" << endl;
		cin >> str_;
	}
	int k = 0; // Текущий приоритет
	int m = 0; // Приоритет последнего элемента в operator_
	for (int i = 0; i < str_.length(); i++){
		if (isOperand(str[i])){
			res_.push(str[i]);
		}
		else if (isOperator(str[i])){
			
			if (str[i] = ')'){
				m = rightBr();
				continue;
			}

			k = priorietyOperator(str[i]);
			if (k < m){
				decreasePriority(k);
				m = k;
				continue;
			}
			m = k;

			operator_.push(str[i]);
		} else {
			continue;
		}
	}
	while(!operator_.isEmpty())
		res_.push(operator_.pop());
}


void setString(const string& str){
	str_ = str;
}
	
int isOperator(const char key)const{
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
	
int isOperand(const char key)const{
	if ((isOperator(key)) || (key = _SPACE_))
		return 0;
	return 1;
}

int priorietyOperator(const char)const{
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
}

VariableType calculate(void){
	VariableType a;
	return a;
}
	
void getValuesOfVariables(void){

}