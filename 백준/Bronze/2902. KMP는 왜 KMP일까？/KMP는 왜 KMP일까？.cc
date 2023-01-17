#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i];
        }
    }
    return 0;
}


