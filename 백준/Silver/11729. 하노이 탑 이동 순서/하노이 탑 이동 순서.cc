#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 10001;
int cnt = 0;
vector<pair<int, int> > v;
void hanoi(int n, int from, int by, int to) {
    if (n == 0) return;
    
    hanoi(n - 1, from, to, by);
    v.push_back({from, to});
    hanoi(n - 1, by, from, to);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    hanoi(N, 1, 2, 3);
    
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }
    
    return 0;
}
