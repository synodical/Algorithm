#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;

ll n, m, sum;
int a, b, ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    vector<ll> v;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    a = 0; b = 0;
    while(1) {
        if(sum >= m) sum -= v[a++]; // 먼저 따져야하는 조건
        else if(b == n) break;
        else sum += v[b++];
        if(sum == m) ans++;
    }
    cout << ans;
    
    return 0;
}
