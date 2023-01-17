// https://psmkr0225.tistory.com/57 참고
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX = 1001;
int x, y, cnt = 0;
string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> x >> y;
    
    for (int i = 1; i <= x; i++) {
        if (i == x) {
            cnt += y;
        }
        else cnt += month[i-1];
    }
    cout << day[cnt % 7];
    return 0;
}