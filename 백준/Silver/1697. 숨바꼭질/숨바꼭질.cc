#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int MAX = 100001;
bool visited[MAX];

void bfs(int n, int k) {
    queue<pair<int, int> > q;
    q.push({n, 0});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        n = cur.first;
        if (n == k) {
            cout << cur.second;
            return;
        }
        if(n > 0 && !visited[n - 1]) {
            q.push({cur.first - 1, cur.second + 1});
            visited[n - 1] = true;
        }
        if(n < 100000 && !visited[n + 1]) {
            q.push({cur.first + 1, cur.second + 1});
            visited[n + 1] = true;
        }
        if(n * 2 <= 100000 && !visited[n * 2]) {
            q.push({cur.first * 2, cur.second + 1});
            visited[n * 2] = true;
        }
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    bfs(N,K);
    return 0;
}


