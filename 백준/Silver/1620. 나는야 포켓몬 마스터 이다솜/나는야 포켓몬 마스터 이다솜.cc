#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
using ll = long long;
const int MAX = 40001;
int n,m;
vector<string> v;
map<string, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
        mp.insert(pair<string, int>(s, i+1));
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (isdigit(s[0])) {
            int ans = stoi(s);
            cout << v[ans - 1] << '\n';
        }
        else {
            cout << mp[s] << '\n';
        }
        
    }
    return 0;
}

