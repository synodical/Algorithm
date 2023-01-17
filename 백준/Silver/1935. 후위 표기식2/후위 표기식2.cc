#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
double num[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cout << fixed;
    cout.precision(2); // 소숫점
    int n;
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> num[i];
    stack<double> st;
    
    for(int i = 0; i < s.size(); i++) {
        if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
            /* 연산자가 나올 경우 피연산자 두개를 pop */
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            
            if (s[i] == '*') {
                st.push((1.0)*b*a);
            }
            else if (s[i] == '/') {
                st.push((1.0)*b / a);
            }
            else if (s[i] == '+') {
                st.push(b + a);
            }
            else if (s[i] == '-') {
                st.push(b - a);
            }
        }
        else { // 피연산자의 경우
            st.push( num[s[i] - 'A'] );
        }
    }
    cout << st.top();
    return 0;
}
