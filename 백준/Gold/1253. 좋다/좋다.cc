#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, a, l, r, sum, cnt = 0;
    cin >> n;
    int v[2010];
    
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v+n);
    
    for(int i = 0; i < n; i++) {
        l = 0; r = n - 1;
        int good = v[i];
        while (l < r) {
            sum = v[l] + v[r];
            if(sum == good) {
                if(l != i && r != i) {
                    cnt++;
                    break;
                }
                else if(l == i) l++;
                else if(r == i) r--;
            }
            else if(sum > good) r--;
            else l++;
            
        }
    }
    cout << cnt;
    return 0;
}
