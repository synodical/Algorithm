#include <iostream>
#include <string>
#define MAX 1001
#define INF 987654321
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T, N, M;
    cin >> T;
    
    while (T--) {
        int ans = 0;
        cin >> N >> M;
        for (int i = N; i <= M; i++) {
            string s = to_string(i);
            for (auto c : s) {
                if (c == '0') {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
