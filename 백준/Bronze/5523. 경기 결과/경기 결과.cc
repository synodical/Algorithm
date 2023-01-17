#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1'000'000'001;
int N, M;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int sum_a=0,sum_b=0;
    while (N--) {
        ll a,b;
        cin >> a >> b;
        if (a>b) {
            sum_a++;
        }
        else if (a<b) sum_b++;
    }
    cout << sum_a << " " << sum_b;
    return 0;
}


