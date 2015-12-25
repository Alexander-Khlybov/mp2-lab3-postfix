#include "postfix.h"

int main(void) {
    string str;
    getline(cin, str);
    map<char, VariableType> m;
    Postfix p;
    string str1;
    try {
        str1 = p.rewriteLineFromInfixToPostfix(str);
    }
    catch (const exception &e) {
        cout << e.what() << endl;
        return 1;
    }
    cout << "Postfix -> " << str1 << endl;
    VariableType res;

    try {
        res = p.calculate(str1, m);
    }
    catch (const exception &e) {
        cout << e.what() << endl;
        return 1;
    }
    cout << "Result : " << res << endl;
    return 0;}
