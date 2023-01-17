#include <iostream>
using namespace std;
const int MAX = 100001;
int n,m;
int Parent[MAX];
int now[MAX] = {0, };
int dp[MAX];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        Parent[i] = a;
    }
    for (int i = 1; i <= m; i++) {
        int a,b;
        cin >> a >> b;
        now[a] += b;
    }
    dp[0]=0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[Parent[i]] + now[i];
        cout << dp[i] << " ";
    }
    return 0;
}
