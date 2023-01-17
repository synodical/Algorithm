#include <iostream>
#include <stack>
#include <string>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    string ans = "";
    stack<char> op;
    cin >> s;
    
    for (char ch : s) {
        if ('A' <= ch && ch <= 'Z') {
            ans += ch;
        } else if (ch == '+' || ch == '-') {
            while (!op.empty() && op.top() != '(') {
                ans += op.top();
                op.pop();
            }
            op.push(ch);
        } else if (ch == '*' || ch == '/') {
            while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
                ans += op.top();
                op.pop();
            }
            op.push(ch);
        } else if (ch == '(') {
            op.push(ch);
        } else {
            while (op.top() != '(') {
                ans += op.top();
                op.pop();
            }
            if (op.top() == '(') {
                op.pop();
            }
        }
    }
    while (!op.empty()) {
        ans += op.top();
        op.pop();
    }
    cout << ans;
    return 0;
}
