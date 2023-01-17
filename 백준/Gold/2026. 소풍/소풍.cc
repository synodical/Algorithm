#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MAX = 900;
int k, n, f;
bool adj[MAX][MAX];
bool visit[MAX];
vector<int> v;

void dfs(int idx, int cnt) {
    
    if (cnt == k) {
        for (int i = 0; i < k; i++) {
            cout << v[i] + 1 << '\n';
        }
        exit(0);
    }
    for (int i = idx; i < n; i++) {
        if (visit[i]) continue;
        bool flag = false;
        for (int j = 0; j < cnt; j++) {
            if (!adj[i][ v[j] ]) {
                flag =true;
                break;
            }
            
        }
        if (flag) continue;

        visit[i] = true;
        v.push_back(i);
        dfs(i, cnt + 1);
        visit[i] = false;
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> k >> n >> f;
    while(f--) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a][b] = true;
        adj[b][a] = true;
    }
    dfs(0, 0);
    cout << "-1\n";

    return 0;
}

