#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    queue<pair<ll,ll>> q;
    q.push({a, 1});
    while(q.size()) {
        pair<ll,ll> cur = q.front();
        q.pop();
        if(cur.first > b) continue;
        if(cur.first == b) {
            cout << cur.second;
            return 0;
        }
        q.push({cur.first * 10 + 1, cur.second + 1});
        q.push({cur.first * 2, cur.second + 1});
    }
    cout << "-1";
    return 0;
}
