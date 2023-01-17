#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MAX = 32001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    char c[2];
    cin >> c[0];
    if (c[0] == 'F') {
        cout << "0.0";
        return 0;
    }
    cin >> c[1];
    if (c[0] == 'A') {
        if (c[1] == '+') cout << "4.3";
        else if (c[1] == '0') cout << "4.0";
        else cout << "3.7";
    }
    else if (c[0] == 'B') {
        if (c[1] == '+') cout << "3.3";
        else if (c[1] == '0') cout << "3.0";
        else cout << "2.7";
    }
    else if (c[0] == 'C') {
        if (c[1] == '+') cout << "2.3";
        else if (c[1] == '0') cout << "2.0";
        else cout << "1.7";
    }
    else if (c[0] == 'D') {
        if (c[1] == '+') cout << "1.3";
        else if (c[1] == '0') cout << "1.0";
        else cout << "0.7";
    }
    return 0;
}
