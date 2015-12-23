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

string Postfix::rewriteLineFromInfixToPostfix(const string& infixString){

if(!infixString.length()){
	throw("String is empty.");
}

checkBrackets(infixString);

map <char, int> operations; 
operations['*'] = 3; operations['/'] = 3; 
operations['+'] = 2; operations['-'] = 2; 
operations['('] = 1;

Stack<char> result;
Stack<char> operationsStack;

char temp;

for (int i = 0; i < infixString.length(); i++){

	temp = infixString[i];

    if (operations.count(temp)) {
        if ((!operationsStack.isEmpty())) {
            char t = operationsStack.pop();
            operationsStack.push(t);

            if ((operations[temp] <= operations[t]) && (temp != '('))
                while (operations[temp] <= operations[t]) {
                    operationsStack.push(operationsStack.pop());

                    if (!operationsStack.isEmpty()) {
                        t = operationsStack.pop();
                        operationsStack.push(t);
                    }
                    else { 
                        break; 
                    }
                }
        }

		operationsStack.push(temp);
		continue;
	}

	if (((temp >= 'a') && (temp <= 'z')) || ((temp >= 'A') && (temp <= 'Z'))) {						
		result.push(temp);
		continue;
	}

	if (temp == ')') {
		if (!operationsStack.isEmpty()){
			char t = operationsStack.pop();
			operationsStack.push(t);

			while (t != '('){
				result.push(t);
				if (!operationsStack.isEmpty()){
					char t = operationsStack.pop();
					operationsStack.push(t);
				} else {break;}
			}

			operationsStack.pop();
			continue;
		}																		
	}
	throw "Incorrect symbol.";
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
