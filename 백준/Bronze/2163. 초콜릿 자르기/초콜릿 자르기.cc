#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    cout << n-1 + n*(m-1);
    return 0;
}

