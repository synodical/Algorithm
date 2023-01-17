#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 1001;
int n,m;
int answer[MAX];
bool used[MAX];
void re(int level, int num) {
    if (level == m) {
        for (int i = 0; i < m; i++) cout << answer[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++) {
        if (used[i]) {
            continue;
        }
        used[i] = true;
        answer[level] = i;
        re(level + 1, num);
        used[i] = false;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    re(0, 1);
    return 0;
}
