#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, r, c, cnt = 0;

void dfs(int x, int y, int size) {
    if (x == r && y == c) {
        cout << cnt;
        return;
    }
    if (r < x + size && r >= x && c < y + size && c >= y) {
        dfs(x, y, size / 2);
        dfs(x, y + size / 2, size / 2);
        dfs(x + size / 2, y, size / 2);
        dfs(x + size / 2, y + size / 2, size / 2);
    }
    else cnt += pow(size, 2);
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> r >> c;
    dfs(0, 0, 1 << n);
    return 0;
}
