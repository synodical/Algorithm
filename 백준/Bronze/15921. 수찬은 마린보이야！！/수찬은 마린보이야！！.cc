#include <iostream>
using namespace std;
using ll = long long;
int n,sum=0;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum+=a;
    }
    if (sum == 0) {
        cout << "divide by zero";
    }
    else cout << "1.00";
    return 0;
}


