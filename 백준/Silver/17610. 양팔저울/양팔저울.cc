#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int k;int sum = 0;
vector<int> v;
set<int> s;
void sol(int idx, int cur_sum) {
    if (idx == k) {
        if (cur_sum >= 1 && cur_sum <= sum)
            s.insert(cur_sum);
        return;
    }
    sol(idx + 1, cur_sum);
    sol(idx + 1, cur_sum - v[idx]);
    sol(idx + 1, cur_sum + v[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        sum += a;
        v.push_back(a);
    }

    sol(0, 0);
    cout << sum - s.size();

    return 0;
}

