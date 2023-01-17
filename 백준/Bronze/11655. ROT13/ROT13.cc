#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 10001;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    while (getline(cin, s)) {
        for (int i=0; i<s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'M')
                s[i] = s[i]+13;

            else if (s[i] >= 'N' && s[i] <='Z')
                s[i] = s[i]-13;

            else if (s[i] >= 'a' && s[i] <='m')
                s[i] = s[i]+13;

            else if (s[i] >= 'n' && s[i] <= 'z')
                s[i] = s[i]-13;
        }
        cout << s;
    }
    return 0;
}