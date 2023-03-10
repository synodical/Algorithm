#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100001;
int n, k;
bool visited[MAX];

int bfs(int first_x, int first_time) {
    queue<pair<int, int>> q;
    q.push({first_x, first_time});
    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();
        if (x == k) {
            return time;
        }
        if (x > 0 && !visited[x - 1]) {
            visited[x - 1] = true;
            q.push({x - 1, time + 1});
        }
        if (x < MAX && !visited[x + 1]) {
            visited[x + 1] = true;
            q.push({x + 1, time + 1});
        }
        if (x * 2 < MAX && !visited[2 * x]) {
            visited[2 * x] = true;
            q.push({2 * x, time + 1});
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    int ans = bfs(n, 0);
    cout << ans;
    return 0;
}
