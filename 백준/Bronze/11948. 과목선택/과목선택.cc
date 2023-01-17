#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a,b,c,d,e,f;
    cin >> a >> b >>c>>d>>e>>f;
    int s1=min(e, f);
    int s2=min({a,b,c});
    s2=min(s2,d);
    cout <<a+b+c+d+e+f - s1-s2;
    return 0;
}


