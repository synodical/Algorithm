#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 1'000'001;
int n, longestD = 0;
vector<int> v;
vector<int> c;
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        c.push_back(a);
    }
    sort(v.begin(), v.end());
    //unique는 리턴값으로 '중복 값 뒤로 미룬 첫번째 위치'를 반환
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < n; i++) {
        cout << lower_bound(v.begin(), v.end(), c[i]) - v.begin() << " ";
    }

    return 0;
}
