#include "postfix.h"
void Postfix::checkBrackets(const string& s)const{
	int leftBrackets = 0;
	int rightBrackets = 0;

	for (int i = 0; i < s.length(); i++){
		if (s[i] == '(') leftBrackets++;
		if (s[i] == ')') rightBrackets++;
	}

	if(leftBrackets != rightBrackets)
		throw("Incorrect line.");
}

string Postfix::rewriteLineFromInfixToPostfix(const string& infixString)const{

if(!infixString.length()){
	throw("String is empty.");
}

checkBrackets(infixString);

map <char, int> operations; 
operations['*'] = 3; operations['/'] = 3; 
operations['+'] = 2; operations['-'] = 2; 
operations['('] = 1; operations['='] = 0;

Stack<char> result;
Stack<char> operationsStack;

char temp;

for (int i = 0; i < infixString.length(); i++){
    if (infixString[i] == _SPACE_)
        continue;
	temp = infixString[i];

    if (operations.count(temp)) {
        char t = '0';
        if ((!operationsStack.isEmpty())) {
            t = operationsStack.pop();
            operationsStack.push(t);
        }
        
            if ((operations[temp] < operations[t]) && (temp != '(')) {
                while ((!operationsStack.isEmpty()) && (operations[temp] < operations[t])) {
                    t = operationsStack.pop();
                    result.push(t);
                }
                if (t == '(') result.pop();
            }
            operationsStack.push(temp);
		continue;
	}
	if (((temp >= 'a') && (temp <= 'z')) || ((temp >= 'A') && (temp <= 'Z'))) {						
		result.push(temp);
		continue;
	}

	if (temp == ')') {
        char t = '0';
			while ((!operationsStack.isEmpty()) && (t != '(')){
                t = operationsStack.pop();
				result.push(t);
			}
            if (t == '(') result.pop();
			continue;
		}																		

	throw ("Incorrect symbol.");
}

while (!operationsStack.isEmpty()){
	result.push(operationsStack.pop());
}

if (result.isEmpty())
	throw "Line doesn't contain an expression.";

string resultString  ="";

while (!result.isEmpty())
	operationsStack.push(result.pop());

while (!operationsStack.isEmpty()) {
	resultString += operationsStack.pop();
}
return resultString;
}

VariableType Postfix::calculate(const string& postfixString, map<char, VariableType> values){
	if (postfixString == "")
		throw("String is empty.");

	Stack<VariableType> result;
	char tmp;
	VariableType leftOperand;
	VariableType rightOperand;

	for (int i = 0; i < postfixString.length(); i++){
		tmp = postfixString[i];

		if (postfixString[postfixString.length() - 1] == '=')
			values[postfixString[0]] = 0;

		if (((tmp >= 'a') && (tmp <= 'z')) || ((tmp >= 'A') && (tmp <= 'Z'))){
			if (!values.count(tmp)){
				cout << "Enter the " << tmp << ": ";
				cin >> values[tmp];
			}
			result.push(values[tmp]);
			continue;
		}

		if (result.isEmpty())
			throw ("Error.");

		rightOperand = result.pop();
		if (result.isEmpty())
			throw ("Error.");
		
		leftOperand = result.pop();
		switch (tmp){
		case '+':
			result.push(leftOperand + rightOperand); 
			break;
		case '-':
			result.push(leftOperand - rightOperand); 
			break;
		case '*':
			result.push(leftOperand * rightOperand); 
			break;
		case '/':
			result.push(leftOperand / rightOperand); 
			break;
		}
	}

	VariableType res = result.pop();
	if (!result.isEmpty())
		throw("Incorrect line.");
	return res;
}