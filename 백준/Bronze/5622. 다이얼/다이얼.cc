#include <iostream>
#include <string>
#include <cstring>
using namespace std;
using ll = long long;
const int MAX = 15;
int arr[]={3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += arr[s[i]-65];
    }
    cout << ans;
    return 0;
}


