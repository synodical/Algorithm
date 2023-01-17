#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 1001;
string s;
vector<string> v;
int main(void) {
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        v.push_back(s.substr(i, s.length()));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < s.length(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}
