#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        stack<char> st;
        bool flag = true; // is VPS
        for (int j = 0; j < s.size(); j++) {
            if(s[j] == '(') st.push('(');
            else if(s[j] == ')') {
                if(!st.empty() ) st.pop();
                else {
                    flag = false; // isn't VPS
                    break;
                }
            }
        }
        if(st.empty() && flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
