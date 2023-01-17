#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

const int MAX = 21;
int a,b,c,h;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        if (!v[0] && !v[1] && !v[2]) {
            break;
        }
        sort(v.begin(), v.end());
        if (v[2] * v[2] == v[1] * v[1] + v[0]*v[0]) {
            cout << "right" << '\n';
        }
        else cout << "wrong" <<'\n';
    }
    return 0;
}

