
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int INF = 1e6;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    int room = 1, cur = 1, cnt = 1;
    while (1) {
        if (cur >= n) {
            break;
        }
        room = 6 * cnt;
        cnt++;
        cur += room;
    }
    cout << cnt;
    return 0;
}

