#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    map<string, int> mp;
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    }
    
    vector<string> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if(mp[v[i]] > mp[v[j]]) { // 원래 i가 작으면 됨, 크면 추월 당한 것
                cnt++;
                break;
            }
        }
    }
    cout << cnt;
    return 0;
}
