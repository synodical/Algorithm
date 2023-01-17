#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000000;
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());
    cout << s;
    return 0;
}
