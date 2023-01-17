#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 102;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int j = 0; j < n- 1; j++) {
        cout << " ";
    }
    cout << "*\n";
    
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j < (n-i-1)*2-1; j++) {
            cout << " ";
        }
        cout << "*\n";
    }
    return 0;
}
