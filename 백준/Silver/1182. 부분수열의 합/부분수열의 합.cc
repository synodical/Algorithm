#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 20;

vector<int> v;
bool check[MAX];
int n, s, cnt = 0;

void dfs(int sum, int level) {
    if (level == n) return;
    if (sum + v[level] == s) cnt++;
    dfs(sum, level + 1);
    dfs(sum + v[level], level + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    dfs(0, 0);
    cout << cnt;
    return 0;
}

 
