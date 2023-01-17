#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 30001;
int n, longestD = 0;
int pos[MAX];
int dist[MAX];
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos, pos+n);
    for (int i = 0; i < n-1; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n-1; i++) {
        if (longestD < pos[i]+dist[i]) {
            longestD = pos[i]+dist[i];
        }
        if(longestD < pos[i+1]){
            cout << "엄마 나 전역 늦어질 것 같아";
            return 0;
        }
    }
    cout << "권병장님, 중대장님이 찾으십니다";
    return 0;
}
