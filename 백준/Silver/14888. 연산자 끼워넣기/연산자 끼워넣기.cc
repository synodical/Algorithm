#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
int n; int input;
int maxx = -INT32_MAX; int minn = INT32_MAX;
vector<int> v;

void dfs(int idx, int cur, int sum, int sub, int mul, int div) {
    if (idx == n) {
        maxx = max(cur, maxx);
        minn = min(cur, minn);
    }
    if ((sum | sub | mul | div) == 0) {
        return;
    }
    if (sum > 0) {
        dfs(idx + 1, cur + v[idx], sum - 1, sub, mul, div);
    }
    if (sub > 0) {
        dfs(idx + 1, cur - v[idx], sum, sub - 1, mul, div);
    }
    if (mul > 0) {
        dfs(idx + 1, cur * v[idx], sum, sub, mul - 1, div);
    }
    if (div > 0) {
        dfs(idx + 1, cur / v[idx], sum, sub, mul, div - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int sum, sub, mul, div;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        v.push_back(input);
    }
    cin >> sum >> sub >> mul >> div;
    dfs(1, v[0], sum, sub, mul, div);
    cout << maxx << '\n' << minn << '\n';
    return 0;
}
