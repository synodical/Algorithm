#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 1000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q1=0,q2=0,q3=0,q4 =0 , a = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        if (x == 0 || y == 0)
            a++;
        
        else if (x < 0) {
            if (y < 0) q3++;
            else q2++;
        }
        else {
            if (y > 0) q1++;
            else q4++;
        }
    }
    cout << "Q1: " << q1 << '\n';
    cout << "Q2: " << q2 << '\n';
    cout << "Q3: " << q3 << '\n';
    cout << "Q4: " << q4 << '\n';
    cout << "AXIS: " << a << '\n';
    return 0;
}