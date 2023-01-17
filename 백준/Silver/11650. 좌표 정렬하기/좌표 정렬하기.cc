#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 10001;
int ans = 0;
vector<pair<int, int> > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << '\n';
    return 0;
}
