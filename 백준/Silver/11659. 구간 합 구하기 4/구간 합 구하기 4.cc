#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;
using ll = long long;

int n, m, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    vector<ll>pre(n + 1);
    for(int i = 1; i <= n; i++) { // important
        cin >> a;
        pre[i] = pre[i - 1] + a;
    }
    while(m--) {
        cin >> a >> b;
        cout << pre[b] - pre[a - 1] << '\n';
    }
    
    return 0;
}


