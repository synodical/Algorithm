
#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 1e5;
 
int n, num, p[MAX + 1], sz;
char c;
bool zero, yuri;
 
void fac(int x) {
    sz = (int)sqrt(x);
    for (int i = 2; i <= sz; i++)
        while (!(x % i)) x /= i, p[i]++;
    if (x > 1) p[x]++;
}
 
void fac2(int x) {
    sz = (int)sqrt(x);
    for (int i = 2; i <= sz; i++)
        while (!(x % i)) x /= i, p[i]--;
    if (x > 1) p[x]--;
}
 
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
 
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (!i) {
            cin >> num;
            if (num < 0) num *= -1;
            else if (num == 0) zero = 1;
            if (num) fac(num);
        }
        else {
            cin >> c >> num;
            if (num < 0) num *= -1;
            else if (num == 0) zero = 1;
            if (c == '/') fac2(num);
            else if (num) fac(num);
        }
    }
    if (zero) cout << "mint chocolate";
    else {
        for (int i = 2; i <= MAX; i++)
            if (p[i] < 0) yuri = 1;
        if (yuri) cout << "toothpaste";
        else cout << "mint chocolate";
    }
}
