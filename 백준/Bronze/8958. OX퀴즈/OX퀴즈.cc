#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 302;
int ans = 0, cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    while (n--) {
        ans = 0; cnt = 1;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'O') {
                if (s[i-1] == 'O') cnt++;
                ans += cnt;
            }
            else cnt = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}