#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < n; j++) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}