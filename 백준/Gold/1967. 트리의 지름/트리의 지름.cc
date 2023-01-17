#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 10001

using namespace std;

bool visited[MAX] = {false, };
vector<pair<int, int>> tree[MAX];
int ans = 0; int x;

void solve(int w, int cur, int prev = -1) { // 가중치, 현재 위치, 그 전에 어딜 방문했는지 (맨 처음은 x가 -1 == 아무데서도 오지 않음)
    if(visited[cur]) return; // visit 조사 후 인접 노드로 이동
    visited[cur] = true;
    if(ans < w) { // 더 긴 지름이 나온다면 갱신
        ans = w;
        x = cur; // x에 가장 먼 정점
    }
    for(int i = 0; i < tree[cur].size(); i++) {
        int next = tree[cur][i].first; // doesn't matter parent or child- 양방향으로 찾을껴
        int d = tree[cur][i].second;
        if(next == prev) continue;
        solve(w + d, next, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int p, c, weight;
        cin >> p >> c >> weight;
        tree[p].push_back({c, weight});
        tree[c].push_back({p, weight});
    }
    
    solve(0, 1); // 임의의 정점에서 가장 먼 정점 찾기
    
    ans = 0;
    memset(visited, false, sizeof(visited));
    
    solve(0, x); // 아까 찾은 정점에서 가장 먼 정점 새로 찾기, 매개변수 x
    cout << ans;
    return 0;
}

