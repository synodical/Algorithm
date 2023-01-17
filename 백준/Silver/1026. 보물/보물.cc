#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 101;
int n, sum=0;
vector<int> a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        a.push_back(input);
    }
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        b.push_back(input);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[n-i-1];
    }
    cout << sum;
}

