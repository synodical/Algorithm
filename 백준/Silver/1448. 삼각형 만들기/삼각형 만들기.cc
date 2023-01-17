#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

vector<int> v;

bool cmp(int a, int b) {
    if(a > b) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < n - 2; i++) {
        if (v[i] < v[i + 1] + v[i + 2]) {
            cout << v[i] + v[i + 1] + v[i + 2];
            return 0;
        }
    }
    cout << "-1";
    return 0;
}

