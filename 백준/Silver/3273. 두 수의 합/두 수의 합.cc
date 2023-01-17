#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,x, ans = 0;
    cin >> n;
    for (int i= 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> x;
    sort(v.begin(), v.end());
    int i=0, j = n-1;
    while (i < j) {
        int sum = v[i]+v[j];
        if (sum == x) {
            ans++;
            i++;
        }
        else if(sum < x) i++;
        else j--;
    }
    cout << ans;
    return 0;
}