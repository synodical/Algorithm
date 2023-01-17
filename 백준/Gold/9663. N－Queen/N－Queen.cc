#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 40;
int n;
int cnt = 0;
bool rc[MAX];      // 같은 열
bool right_d[MAX]; // 우상 대각
bool left_d[MAX];  // 좌상 대각

void sol(int j) {
    if (j == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) { // row
        if (rc[i] || right_d[i + j] || left_d[i - j + n - 1]) {
            continue;
        }
        rc[i] = right_d[i + j] = left_d[i - j + n - 1] = true;
        sol(j + 1);
        rc[i] = right_d[i + j] = left_d[i - j + n - 1] = false;
    }
}
int main() {
    cin >> n;
    sol(0);
    cout << cnt;
    return 0;
}
