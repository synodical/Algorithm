#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 93;
int sum = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        int st, apple;
        cin >> st >> apple;
        sum += apple % st;
    }
    cout << sum;
    return 0;
}

