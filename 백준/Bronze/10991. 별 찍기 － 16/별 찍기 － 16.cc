#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX = 1001;
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
        cout << '\n';
    }
    return 0;
}