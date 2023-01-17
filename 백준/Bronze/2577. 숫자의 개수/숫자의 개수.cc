#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int INF = 10001;
int arr[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b, c, zero = 0;
    cin >> a >> b >> c;
    int total = a*b*c;
    
    while (total > 0) {
        int n = total % 10;
        total /= 10;
        if (n == 0) zero++;
        else arr[n]++;
    }
    cout << zero << '\n';
    for (int i = 1; i <= 9; i++) {
        cout << arr[i] << '\n';
    }
    return 0;
}