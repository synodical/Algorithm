#include <iostream>
#include <string>
#include <queue>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, cnt =0;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        if (a == n) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
