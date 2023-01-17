#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 102;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s[5];
    for (int i = 0; i < 5; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < s[j].size()) {
                cout << s[j][i];
            }
        }
    }

    return 0;
}