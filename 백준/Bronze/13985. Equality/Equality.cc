#include <iostream>
#include <queue>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 1001;
int d1, d2, n;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> d1 >> s >> d2 >> s >> n;
    if (d1+d2 == n) {
        cout<<"YES";
    }
    else cout << "NO";
    return 0;
}


