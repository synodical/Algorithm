#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1e8;
const int MAX = 500003;
string a,b;
char c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> c >> b;
    if (c == '*') {
        cout << "1";
        for (int i = 0; i < a.size() + b.size() - 2; i++) {
            cout << "0";
        }
    }
    else {
        if (a.size() > b.size()) {
            cout << "1";
            for (int i = 0; i < a.size() - b.size() - 1; i++) {
                cout << "0";
            }
            cout << "1";
            for (int i = 0; i < b.size() - 1; i++) {
                cout << "0";
            }
        }
        else if (a.size() < b.size()) {
            cout << "1";
            for (int i = 0; i < b.size() - a.size()- 1; i++) {
                cout << "0";
            }
            cout << "1";
            for (int i = 0; i < a.size() - 1; i++) {
                cout << "0";
            }
        }
        else {
            cout << "2";
            for (int i = 0; i < a.size()-1; i++) {
                cout << "0";
            }
        }
    }
    return 0;
}

