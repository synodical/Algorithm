#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAX = 21;
int x,y,w,h;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>x>>y>>w>>h;
    int a = min(abs(w-x), abs(h-y));
    int b = min(x, y);
    cout << min(a, b);
    return 0;
}

