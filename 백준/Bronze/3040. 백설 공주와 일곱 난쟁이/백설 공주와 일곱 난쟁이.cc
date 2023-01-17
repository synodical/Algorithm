#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
int d[10];
int sum = 0,a,b;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 9; i++) {
        cin >> d[i];
        sum += d[i];
    }
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - d[i] - d[j] == 100) {
                a=i; b=j;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (i==a || i==b) {
            continue;
        }
        cout << d[i] << '\n';
    }
    return 0;
}


