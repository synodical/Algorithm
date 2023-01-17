#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 1e6;
int n, x1,y1,r1,x2,y2,r2;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int d = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
        int sd = (r1-r2) * (r1-r2);
        int ld = (r1+r2) * (r1+r2);
        if(d == 0) {
            if(sd == 0)
                cout << "-1\n";
            else
                cout << "0\n";
        }
        else if (d == sd || d == ld)
            cout << "1\n";
        else if (sd < d && d < ld)
            cout << "2\n";
        else
            cout << "0\n";
    }
    return 0;
}


