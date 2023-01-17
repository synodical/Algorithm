#include <iostream>
using namespace std;
using ll = long long;
int n,sum=0;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    double a,b,c;
    cin >> a >> b >> c;
    cout << int(max(a/b*c, a*b/c));
    
    return 0;
}


