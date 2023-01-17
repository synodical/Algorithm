#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 100002;
int n, cnt = 0;
bool flag = false;
vector<pair<int, int>> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int start = 100 * a + b;
        int end = 100 * c + d;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end());
    
    int date = 301; int last = 0; int i = -1;
    while (date <= 1130 && i < n) {
        flag = false; i++;
        for (int j = i; j < n; j++) {
            if (v[j].first > date) break;
            if (v[j].second > last) {
                last = v[j].second;
                flag = true;
                i = j;
            }
        }
        if (flag) {
            date = last;
            cnt++;
        }
        else {
            cout << "0";
            return 0;
        }
    }
    cout << cnt;
    return 0;
}
