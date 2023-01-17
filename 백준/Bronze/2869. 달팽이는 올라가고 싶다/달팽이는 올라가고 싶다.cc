#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int INF = 10001;
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b,v;
    cin >> a >> b >> v;
    cout << (v-b-1) / (a-b) + 1;
    return 0;
}