#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 21;
vector<pair<int, int> > v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 0; i < 3; i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    if (v[0].first == v[1].first) {
        cout << v[2].first << " ";
    }
    else if (v[1].first == v[2].first) {
        cout << v[0].first << " ";
    }
    else cout << v[1].first << " ";
    
    if (v[0].second == v[1].second) {
        cout << v[2].second << " ";
    }
    else if (v[1].second == v[2].second) {
        cout << v[0].second << " ";
    }
    else cout << v[1].second << " ";
    return 0;
}

