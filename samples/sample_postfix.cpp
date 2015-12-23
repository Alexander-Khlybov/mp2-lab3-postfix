#include "postfix.h"

int main(void) {
    string str = "";
    cout << "Enter the arithmetic expression: (\\ - is end of line)" << endl;
    char t;
    cin >> t;

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
