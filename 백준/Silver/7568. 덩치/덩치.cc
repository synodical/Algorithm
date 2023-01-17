#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,x, ans = 0;
    cin >> n;
    for (int i= 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                ans++;
            }
        }
        cout << ans+1 << " ";
        ans = 0;
    }
    return 0;
}