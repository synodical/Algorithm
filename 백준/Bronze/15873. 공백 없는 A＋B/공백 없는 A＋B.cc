#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 10002;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    if (s.size() == 4) {
        cout << "20";
    }
    else if (s.size() == 3) {
        if (s[2] == '0') cout << 10 + s[0]-'0';
        else cout << 10 + s[2]-'0';
    }
    else cout << s[0]-'0' + s[1]-'0';
    return 0;
}