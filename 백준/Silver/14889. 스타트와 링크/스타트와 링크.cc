#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int MAX = 20;
int MIN = 210000000;
bool check[MAX];
int n, S[MAX][MAX];

void dfs(int idx, int cnt) {
    vector<int> start;
    vector<int> link;
    int sum_start = 0;
    int sum_link = 0;
    
    if (cnt == (n/2)) {
        for (int i = 0; i < n; i++) {
            if (check[i]) start.push_back(i);
            else link.push_back(i);
        }
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                sum_start += S[start[i]][start[j]];
                sum_link += S[link[i]][link[j]];
            }
        }
        if (abs(sum_link - sum_start) < MIN)
            MIN = abs(sum_link - sum_start);
    }
    for (int i = idx; i < n; i++) {
        if (check[i] == true) continue;
        check[i] = true;
        dfs(i, cnt + 1);
        check[i] = false;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> S[i][j];
        }
    }
    dfs(0, 0);
    cout << MIN;
    return 0;
}

