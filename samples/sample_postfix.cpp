#include "postfix.h"

int main(void) {
    string str = "a*(b+c-d)+(d/(f-c)-(k+l)/s)";
   /* cout << "Enter the arithmetic expression: (\\ - is end of line)" << endl;
    char t;
    cin >> t;

    // цикл позволяет писать строку с пробелами.
    while (t != '\\') {
        str += t;
        cin >> t;
    }*/

    map<char, VariableType> m;
    Postfix p;
    string str1 = p.rewriteLineFromInfixToPostfix(str);
    cout << "Postfix -> " << str1 << endl;
    VariableType res = p.calculate(str1, m);
    cout << res << endl;
    return 0;}
