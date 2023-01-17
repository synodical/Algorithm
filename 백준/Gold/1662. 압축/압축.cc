#include <iostream>
#include <string>
#include <stack>
using namespace std;
using ll = long long;

string s;
stack<int> st;
int ans = 0, visited[50];

int dfs(int start, int end) {
    int ans = 0;
    for (int i = start; i < end; i++) {
        if (s[i] == '(') {
            int t = s[i - 1] - '0';
            ans += t * dfs(i + 1, visited[i]) - 1;
            i = visited[i];
        }
        else ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')') {
            visited[st.top()] = i;
            st.pop();
        }
    }
    cout << dfs(0, s.length());
    return 0;
}

 
