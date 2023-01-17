#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int INF = 10001;
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, i = 0;
    cin >> x;
    while (x > 0) {
        i++;
        x -= i;
    }
    if (i % 2) {
        cout << 1 - x << "/" << x + i;
    }
    else {
        cout << x + i << "/" << 1 - x;
    }
    return 0;
}