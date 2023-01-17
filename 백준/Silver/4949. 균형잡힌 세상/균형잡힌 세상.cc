#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    while (1) {
        string s;
        getline(cin, s);
        bool x = true; // )(
        stack <char> st;
    
        if (s.length() == 1 && s[0] == '.') break;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[') st.push(s[i]);
            else if(s[i] == ')') {
                if(!st.empty() && st.top() == '(') st.pop();
                else {
                    x = false;
                    break;
                }
            }
            else if(s[i] == ']') {
                if(!st.empty() && st.top() == '[') st.pop();
                else {
                    x = false;
                    break;
                }
            }
        }
        if(x && st.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
