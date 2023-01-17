#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#define INF 987654321
using namespace std;
using ll = long long;
ll a;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<string,ll> mp;
    while (n--) {
        string s;
        cin >> s;
        if(mp.find(s) == mp.end()) mp.insert({s, 1});
        else mp.find(s)->second++;
        a = max(a, mp.find(s)->second);
    }
    map<string, ll>::iterator iter;
    for (iter = mp.begin(); iter != mp.end(); iter++) {
        if(iter->second == a) {
            cout << iter->first;
            return 0;
        }
    }
    return 0;
}
