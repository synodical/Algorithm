#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
using ll = long long;
const int MAX = 102;
int sum = 0;
int arr[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while (1) {
        string s, re;
        cin >> s;
        if (s == "0") return 0;
        re = s;
        reverse(re.begin(), re.end());
        if (re == s) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
