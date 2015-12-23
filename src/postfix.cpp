#include "postfix.h"

Postfix::Postfix(void){
	operator_ = new Stack<char>();
	res_ = new Stack<char>();
	expResult_ = new Stack<VariableType>();
	str_ = "";
    resStr_ = "";
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
    try {
        j = operator_->pop();
    }
    catch (...) {
        j = '(';
    }
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
		if (checkingLine())
			throw("Incorrect line.");
	}

	int k = 0; // Текущий приоритет
	int m = 0; // Приоритет последнего элемента в operator_


	for (int i = 0; i < (int)str_.length(); i++){
		if (isOperand(str_[i])){
			res_->push(str_[i]);
		}
		else if (isOperator(str_[i])){
			
			if (str_[i] == ')'){
				m = rightBr();
				continue;
			}

            k = priorietyOperator(str_[i]);
            if (k < m) {
                decreasePriority(k);
            }
            m = k;
            
			operator_->push(str_[i]);
		} else {
			continue;
		}
	}
	while(!operator_->isEmpty())
		res_->push(operator_->pop());


    Stack<char>* tmp(res_);
    Stack<char>* toStr = new Stack<char>;

    while (!(tmp->isEmpty()))
        toStr->push(tmp->pop());

    while (!(toStr->isEmpty()))
        resStr_ += toStr->pop();
    op = 1;
}

int Postfix::setString(const string& str){
	str_ = str;
	int t = checkingLine();
    op = 0;
    return t;
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
		return 1;


	int i = 0;
	int j = 1;
	char temp1;
	char temp2;
	if (str_.length() > 0)
		if (isOperator(str_[0]))
			if ((str_[0] != '-') && (str_[0] != '('))
				return 1;

	while (j < str_.length()) {
		if (str_[j] == _SPACE_){
			j++;
			continue;
		} else {
			temp1 = str_[i];
			temp2 = str_[j];
			if((isOperand(temp1)) && (isOperand(temp2)))
				return 1;
			if((isOperator(temp1)) && (isOperator(temp2)))
				if (((temp1 == '(') && (temp2 != ')') && (temp2 != '(') && (temp2 != '-')) || ((temp1 != '(') && (temp2 == ')') && (temp1 != ')')))
					return 1;
			i = j++;
		}
	}

	return 0;
}

VariableType Postfix::calculate(void){
	if (!op)
		throw("No data.");

	VariableType leftOperand = 0, rightOperand = 0, value_ = 0;

	for (int i = 0; i < resStr_.length(); i++){

		if (isOperand(resStr_[i])){
			cout << "Enter the '" << resStr_[i] << "'" << endl;
			cin >> value_;
			expResult_->push(value_);
			continue;
		}

		if (expResult_->isEmpty())
			throw("Error.");
		leftOperand = expResult_->pop();
		if (expResult_->isEmpty())
            if (resStr_[i] != '-') {
                leftOperand = -leftOperand;
                expResult_->push(leftOperand);
                continue;
            } else
    			throw("Error.");
		rightOperand = expResult_->pop();

		switch (resStr_[i]){
		case '+':
			expResult_->push(leftOperand + rightOperand);
			break;
		case '-':
			expResult_->push(leftOperand - rightOperand); 
			break;
		case '*':
			expResult_->push(leftOperand * rightOperand); 
			break;
		case '/':
			expResult_->push(leftOperand / rightOperand); 
			break;
		}
   	}
	return expResult_->pop();
}

void Postfix::printPostfix(void) {
    if (op) {
        cout << resStr_ << endl;
    } else {
        cout << "The source string was not processed." << endl;
    }
}