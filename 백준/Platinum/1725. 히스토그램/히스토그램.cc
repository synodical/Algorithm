#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 100002;
int n, arr[MAX], ans = 0;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    st.push(0);
    for (int i = 1; i <= n + 1; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            int height = arr[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            ans = max(ans, height * width);
        }
        st.push(i);
    }
    cout << ans;
    return 0;
}
