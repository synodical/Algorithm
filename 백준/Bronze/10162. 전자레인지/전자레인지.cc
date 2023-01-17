#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    if (t % 10 != 0) {
        cout << -1;
        return 0;
    }
    cout << t / 300 << " " << (t % 300) / 60 << " " << (t % 60) / 10;
    
    return 0;
}
