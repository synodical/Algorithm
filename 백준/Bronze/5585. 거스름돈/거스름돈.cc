#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int coin[] = { 500,100,50,10,5,1 };
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,i=0,ans=0;
    cin >> n;
    n = 1000-n;
    while (n) {
        if (coin[i] > n) {
            i++;
            continue;
        }
        else {
            n-=coin[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}


