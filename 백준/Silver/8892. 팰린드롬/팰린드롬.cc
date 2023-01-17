#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int t;
vector<string> v;
int palindrome() {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            string before1 = "", before2 = "", t1, t2;
            before1 = v[i] + v[j];
            before2 = v[j] + v[i];
            t1 = before1;
            t2 = before2;
            reverse(t1.begin(), t1.end());
            reverse(t2.begin(), t2.end());
            if (before1 == t1) {
                cout << before1 << '\n';
                return 0;
            }
            if (before2 == t2) {
                cout << before2 << '\n';
                return 0;
            }
        }
    }
    cout << "0\n";
    v.clear();
    return 0;
}
int main(void) {
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }
        palindrome();
        v.clear();
    }
    return 0;
}
