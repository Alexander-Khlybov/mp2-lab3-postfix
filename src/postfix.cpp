#include "postfix.h"

Postfix::Postfix(void){
	operator_ = new Stack<char>();
	res_ = new Stack<char>();
	expResult_ = new Stack<VariableType>();
	str_ = "";
	op = 0;
}

Postfix::~Postfix(void){
	delete operator_;
	delete res_;
	delete expResult_;
}

int Postfix::rightBr(void){
	char j = operator_->pop();
	while(j != '('){
		res_->push(j);
		j =  operator_->pop();
	}
	j = operator_->pop();
	operator_->push(j);
	return priorietyOperator(j);
}

void Postfix::decreasePriority(int k){
	char j = operator_->pop();
	while( (k <= priorietyOperator(j)) && (!operator_->isEmpty() )){
		res_->push(j);
		j = operator_->pop();
	}
	if (priorietyOperator(j) < k)
		operator_->push(j);
	operator_->push(k);
}

void Postfix::procStr(void){
	if (str_.length() == 0){
		cout << "Enter the expression" << endl;
		cin >> str_;
		if (!checkingLine())
			throw("Incorrect line.");
	}
	int k = 0; // Текущий приоритет
	int m = 0; // Приоритет последнего элемента в operator_
	for (int i = 0; i < (int)str_.length(); i++){
		if (isOperand(str_[i])){
			res_->push(str_[i]);
			op++;
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

			operator_->push(str_[i]);
		} else {
			continue;
		}
	}
	while(!operator_->isEmpty())
		res_->push(operator_->pop());
}

void Postfix::setString(const string& str){
	str_ = str;
	checkingLine();
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
		}
    return -1;
}

int Postfix::checkingLine(void)const {

	int leftBracket = 0;
	int rightBracket = 0;

	for (int k = 0; k < str_.length(); k++){
		if (str_[k] == '(') leftBracket++;
		if (str_[k] == ')') rightBracket++;
	}

	if (leftBracket != rightBracket)
		return 0;


	int i = 0;
	int j = 1;
	char temp1;
	char temp2;
	if (str_.length() > 0)
		if (isOperator(str_[0]))
			if ((str_[0] != '-') && (str_[0] != '('))
				return 0;

	while (j < str_.length()) {
		if (str_[j] == _SPACE_){
			j++;
			continue;
		} else {
			temp1 = str_[i];
			temp2 = str_[j];
			if((isOperand(temp1)) && (isOperand(temp2)))
				return 0;
			if((isOperator(temp1)) && (isOperator(temp2)))
				if (((temp1 == '(') && (temp2 != ')') && (temp2 != '(') && (temp2 != '-')) || ((temp1 != '(') && (temp2 == ')') && (temp1 != ')')))
					return 0;
			i = j++;
		}
	}

	return 1;
}

VariableType Postfix::calculate(void){
	VariableType a = 0;
	return a;
}
	
void Postfix::getValuesOfVariables(void){

}

void Postfix::printPostfix(void)const {

}