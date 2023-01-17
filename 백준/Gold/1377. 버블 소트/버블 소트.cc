#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
vector<pair<int, int> > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back({a, i});
    }
    sort(v.begin(), v.end());
    int max = -1;
    for (int i = 0; i < n; i++) {
        if (max < v[i].second - i) {
            max = v[i].second - i;
        }
    }
    cout << max + 1;
    return 0;
}

