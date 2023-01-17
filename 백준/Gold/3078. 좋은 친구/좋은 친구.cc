#include <iostream>
#include <string>
#include <queue>
using namespace std;
using ll = long long;
const int MAX = 1000000;
ll n, k,cnt=0;
queue<int> q[23];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int len = s.length();
        
        while (!q[len].empty() && i - q[len].front() > k) {
            q[len].pop();
        }
        cnt += q[len].size();
        q[len].push(i);
    }
    cout << cnt;
    return 0;
}

 
