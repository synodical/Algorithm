#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 100001;
int n,l,ans=1;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> l;
    vector<int> v;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int tmp = l-1;
    for (int i = 0; i < n-1; i++) {
        if (v[i+1] - v[i] <= tmp) {
            tmp -= v[i+1] - v[i];
        }
        else {
            tmp =l-1;
            ans++;
        }
    }
    cout << ans;

    return 0;
}
