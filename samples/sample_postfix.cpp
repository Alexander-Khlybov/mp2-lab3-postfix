#include "postfix.h"

int main(void) {
    string str = "";
    cout << "Enter the arithmetic expression: (\\ - is end of line)" << endl;
    char t;
    cin >> t;

    // ���� ��������� ������ ������ � ���������.
    while (t != '\\') {
        str += t;
        cin >> t;
    }

    map<char, VariableType> m;
    Postfix p;
    string str1 = p.rewriteLineFromInfixToPostfix(str);
    cout << "Postfix -> " << str1 << endl;
    VariableType res = p.calculate(str1, m);
    cout << res << endl;
    return 0;}
