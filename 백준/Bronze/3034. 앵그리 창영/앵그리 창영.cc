#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 1516;
int n,w,h;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> w >> h;
    while (n--) {
        int cross = w*w + h*h;
        int a;
        cin >> a;
        if (cross < a*a) cout << "NE\n";
        else cout << "DA\n";
    }
    return 0;
}
