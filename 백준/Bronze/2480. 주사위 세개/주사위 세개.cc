#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int cnt = 0;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[1] == v[2]) cout << 10000 + (v[0] * 1000);
    else if (v[0] == v[1]) cout << 1000 + (v[0] * 100);
    else if (v[0] == v[2]) cout << 1000 + (v[0] * 100);
    else if (v[1] == v[2]) cout << 1000 + (v[1] * 100);
    else cout << v[2] * 100;

    return 0;
}