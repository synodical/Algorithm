#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;

ll G, a, b, c;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    a = 0; b = 0;
    vector<ll> v, ans;
    cin >> G;
    for (ll i = 1; i <= 200000; i++)
        v.push_back(i * i);
    
    while(1) {
        if (b >= v.size()) break;
        ll sub = v[b] - v[a];
        if(sub < G) b++;
        else if(sub > G) a++;
        else {
            ans.push_back(sqrt(v[b]));
            b++;
        }
    }
    if(ans.size() == 0) cout << "-1";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
    
    return 0;
}
