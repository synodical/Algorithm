#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x,y, x1,x2,y1,y2;
    
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x >> y;
    
    int a,b;
    a = max(abs(x1-x), abs(y1-y));
    b = abs(x2-x) + abs(y2-y);
    
    if (a<b) {
        cout << "bessie";
    }
    else if (a>b) cout << "daisy";
    else cout << "tie";
    return 0;
}


