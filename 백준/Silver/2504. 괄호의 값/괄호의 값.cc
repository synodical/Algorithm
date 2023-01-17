#include <iostream>
#include <string>
#include <stack>
using namespace std;
using ll = long long;
const int MAX = 5000000;
string s;
stack<char> st;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int ans = 0, temp = 1;
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            temp *= 2;
            st.push('(');
        }
        else if(s[i] == '[') {
            temp *= 3;
            st.push('[');
        }
        else if(s[i] == ']') {
            if (st.empty() || st.top() != '[') {
                ans = 0;
                break;
            }
            if(s[i - 1] == '[') {
                ans += temp;
                temp /= 3;
                st.pop();
            }
            else {
                temp /= 3;
                st.pop();
            }
        }
        else if(s[i] == ')') {
            if (st.empty() || st.top() != '(') {
                ans = 0;
                break;
            }
            if(s[i - 1] == '(') {
                ans += temp;
                temp /= 2;
                st.pop();
            }
            else {
                temp /= 2;
                st.pop();
            }
        }

    }
    if (!st.empty()) {
        ans = 0;
    }
    cout << ans;
    return 0;
}

 
