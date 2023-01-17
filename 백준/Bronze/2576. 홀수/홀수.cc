// 결론: 우선순위 큐를 쓰니 코드도 간결하고 정말 이해가 쉽구나!!
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1e6;
int sum = 0, Min = INF;
bool isOdd = false;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 7; i++) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            isOdd = true;
            sum += a;
            Min = min(a, Min);
        }
    }
    if(!isOdd) {
        cout << "-1";
        return 0;
    }
    cout << sum << '\n' << Min;
    return 0;
}

