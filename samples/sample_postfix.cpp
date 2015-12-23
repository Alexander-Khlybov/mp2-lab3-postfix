#include "postfix.h"

int main(void) {
    string str = "";
    cout << "Enter the arithmetic expression:" << endl;
    char t;
    cin >> str;

    // цикл позволяет писать строку с пробелами.
    while (t != '\\') {
        str += t;
        cin >> t;
    }

    Postfix p;
    int tmp = p.setString(str);
    p.procStr();
    p.printPostfix();
    VariableType res = p.calculate();
    cout << res << endl;
    return 0;}
