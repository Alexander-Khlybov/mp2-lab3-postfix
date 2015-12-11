#ifndef _POSTFIX_H_
#define _POSTFIX_H_
#include "stack.hpp"

#define _SPACE_ " "

typedef double VariableType;

template <class KeyType>
class Postfix {
private:
	int rightBr(void);
	void decreasePriority(int);
	int  priorietyOperator(const char)const;
	int  isOperator(const char)const;
	int  isOperand(const char)const;
	Stack<KeyType> res_;
	Stack<KeyType> operator_;
	string str_ = "0";
public:
	Postfix();
	~Postfix();

	void procStr(void);
	void setString(const string&);
	VariableType calculate(void);
	void getValuesOfVariables(void);
};

template <class KeyType>
Postfix<KeyType>::Postfix(){
	operator_ = new Stack<KeyType>();
	res_ = new Stack<KeyType>();
}

template <class KeyType>	
Postfix<KeyType>::~Postfix(void){

}

template <class KeyType>
int Postfix<KeyType>::rightBr(void){
	KeyType j = operator_.pop();
	while(j != "("){
		res_.push(j);
		j =  operator_.pop();
	}
	j = operator_.pop();
	operator_.push(j);
	return priorietyOperator(j);
}

template <class KeyType>
void Postfix<KeyType>::decreasePriority(int k){
	KeyType j = operator_.pop();
	while( (k <= priorietyOperator(j)) && (!operator_.isEmpty() )){
		res_.push(j);
		j = operator_.pop();
	}
	if (priorietyOperator(j) < k)
		operator_.push(j);
	operator_.push(k);
}

template <class KeyType>
void Postfix<KeyType>::procStr(void){
	if (str_ == "0"){
		cout << "Enter the expression" << endl;
		cin >> str_;
	}
	int k = 0; // Текущий приоритет
	int m = 0; // Приоритет последнего элемента в operator_
	for (int i = 0; i < str_.length(); i++){
		if (isOperand(str_[i])){
			res_.push(str_[i]);
		}
		else if (isOperator(str_[i])){
			
			if (str_[i] = ")"){
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


template <class KeyType>
void Postfix<KeyType>::setString(const string& str){
	str_ = str;
}
	
template <class KeyType>
int Postfix<KeyType>::isOperator(const char key)const{
	switch (key)
	{
		case "+":
			return 1;
		case "-":
			return 1;
		case "*":
			return 1;
		case "/":
			return 1;
		case "(":
			return 1;
		case ")":
			return 1;
		case "=":
			return 1;
		default:
			return 0;
	}
}
	
template <class KeyType>
int Postfix<KeyType>::isOperand(const char key)const{
	if ((isOperator(key)) || (key == _SPACE_))
		return 0;
	return 1;
}

template <class KeyType>
int Postfix<KeyType>::priorietyOperator(const char)const{
	if (isOperator(key))
		switch (key)
		{
			case "+":
				return 2;
			case "-":
				return 2;
			case "*":
				return 3;
			case "/":
				return 3;
			case "(":
				return 1;
			case ")":
				return 1;
			case "=":
				return 0;
		}
}

template <class KeyType>
VariableType Postfix<KeyType>::calculate(void){
	VariableType a;
	return a;
}
	
template <class KeyType>
void Postfix<KeyType>::getValuesOfVariables(void){

}

#endif