#include <iostream>
#include <queue>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 300001;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, sum_a=100, sum_b=100;
    cin >> n;
    while (n--) {
        int a,b;
        cin >> a >> b;
        if (a==b) {
            continue;
        }
        else if (a < b) sum_a -= b;
        else sum_b -= a;
    }
    cout << sum_a << '\n' << sum_b;
    return 0;
}


