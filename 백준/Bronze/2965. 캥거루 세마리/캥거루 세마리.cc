#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 5000001;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(c-b, b-a) - 1;
    return 0;
}
