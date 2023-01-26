#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 100001;
int n, k;
bool visited[MAX];

pair<int, int> bfs(int first_x, int first_time) {
    fill(visited, visited + MAX, false);
    queue<pair<int, int>> q;
    q.push({first_x, first_time});
    visited[first_x] = true;
    int cnt = 0, min_time = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[x] = true;
        if (x == k) {
            if (cnt == 0) { // 처음으로 목표 위치에 도달
                cnt++;
                min_time = time;
            } else if (cnt > 0 && time == min_time) { // 처음 이후 도달이자, 최소 시간인경우
                cnt++;
            }
        }
        if (x > 0 && !visited[x - 1]) {
            q.push({x - 1, time + 1});
        }
        if (x < MAX && !visited[x + 1]) {
            q.push({x + 1, time + 1});
        }
        if (x * 2 < MAX && !visited[x * 2]) {
            q.push({2 * x, time + 1});
        }
    }
    return make_pair(min_time, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    auto ans = bfs(n, 0);
    cout << ans.first << '\n' << ans.second;
    return 0;
}

