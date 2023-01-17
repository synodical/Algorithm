#include <iostream>
#include <queue>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 300001;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int e,f,g,h;
        cin >> e >> f >> g >> h;
        int hp,mp,attack, prevent;
        hp = a+e; mp =b+f; attack=c+g; prevent =d+h;
        if (hp < 1) {
            hp = 1;
        }
        if (mp < 1) {
            mp = 1;
        }
        if (attack < 0) {
            attack = 0;
        }
        cout << 1*hp + 5*mp+2*attack+2*prevent << '\n';
    }
    return 0;
}


