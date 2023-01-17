#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int n, k;
vector<string> v;
bool cmp(string s1, string s2) {
    if (s1.length() == s2.length()) {
        int sum_s1 = 0, sum_s2 = 0;
        for (int i = 0; i < s1.length(); i++) {
            if ('0' <= s1[i] && s1[i] <= '9') {
                sum_s1 += s1[i] - '0';
            }
            if ('0' <= s2[i] && s2[i] <= '9') {
                sum_s2 += s2[i] - '0';
            }
        }
        if (sum_s1 != sum_s2) {
            return sum_s1 < sum_s2;
        }
        else return s1 < s2;
    }
    else return s1.length() < s2.length();
}
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}

