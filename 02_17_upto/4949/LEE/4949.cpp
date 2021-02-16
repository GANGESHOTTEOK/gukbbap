#include <iostream>
#include <stack>
#include <string>

using namespace std;

string input = "";

void read() { getline(cin, input); }

bool isBalanced() {
    stack <char> brace;
    for (int i = 0; input[i] != '.'; i++) {
        if (input[i] == '(') brace.push('(');
        else if (input[i] == ')') {
            if (brace.empty()) return false;
            else if (brace.top() == '[') return false;
            brace.pop();
        }
        else if (input[i] == '[') brace.push('[');
        else if (input[i] == ']') {
            if (brace.empty()) return false;
            else if (brace.top() == '(') return false;
            brace.pop();
        }
    }
    if (!brace.empty()) return false;
    return true;
}
int main(void) {
    read();
    while (input != ".") {
        if (isBalanced()) cout << "yes\n";
        else cout << "no\n";
        read();
    }
    return 0;
}


