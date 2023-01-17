// 결론: 우선순위 큐를 쓰니 코드도 간결하고 정말 이해가 쉽구나!!
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1e6;
int c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> c;
    for (int i = 0; i < c; i++) {
        double n; double avg = 0; int cnt = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            avg += v[i];
        }
        avg /= n;
        
        for (int i = 0; i < n; i++) {
            if (v[i] > avg) {
                cnt++;
            }
        }
        double ans = (double)cnt / n * 100;
        cout << fixed;
        cout.precision(3);
        cout << ans << "%\n";
    }
    return 0;
}

