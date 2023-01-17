#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 302;
int alphabet[27] = {-1, };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++) {
        alphabet[i] = -1;
    }
    for (int i = 0; i < s.size(); i++) {
        if (alphabet[(int)(s[i] - 97)] == -1) {
            alphabet[(int)(s[i] - 97)] = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
    return 0;
}