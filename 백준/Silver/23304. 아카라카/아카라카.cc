#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isAka(string s) {
    int len = s.length();
    if (len == 1) {
        return true;
    }
    string l = s.substr(0, len / 2);
    string r = s.substr((len + 1) / 2, len);
    if (l != r) {
        return false;
    }
    if (isAka(l) && isAka(r)) {
        return true;
    }
    return false;
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    if (isAka(str)) {
        cout << "AKARAKA";
    }
    else cout << "IPSELENTI";
    return 0;
}