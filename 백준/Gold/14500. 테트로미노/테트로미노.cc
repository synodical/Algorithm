#include <iostream>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;
// O(NM)
const int MAX = 500;
int n, m;
int board[MAX][MAX];

pair<int, int> Tet[][4] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {0, 1}},
    
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},

    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {-1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
};

void sol() {
    int sum = 0, ans = 0;
    for (int i = 0; i < 19; i++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                sum = 0;
                for (auto cur : Tet[i]) {
                    int nx = x + cur.first;
                    int ny = y + cur.second;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                        sum = 0;
                        break;
                    }
                    sum += board[nx][ny];
                }
                ans = max(ans, sum);
                
            }
        }
    }
    
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    sol();

    return 0;
}

