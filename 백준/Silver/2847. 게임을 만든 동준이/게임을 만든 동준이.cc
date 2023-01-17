#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, a;
vector<int> v;
int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }

    a = 0;
    for(int i = n - 2; i >= 0; i--) {
        if(v[i + 1] <= v[i]) {
            a += v[i] - (v[i + 1] - 1);
        }
        v[i] = min(v[i], v[i + 1] - 1); // 현재 원소 변화
    }
    
    cout << a;
    return 0;
}
