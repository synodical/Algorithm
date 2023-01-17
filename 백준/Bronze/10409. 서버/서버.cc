#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;
const int MAX = 100001;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, T, sum = 0;
    cin >> n >> T;
    for (int i = 0; i < n; i++) {
        int job;
        cin >> job;
        if (sum + job > T) {
            cout << i;
            return 0;
        }
        sum += job;
    }
    cout << n;
    return 0;
}


