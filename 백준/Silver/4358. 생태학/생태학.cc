#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

double total = 0;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    map<string, double> mp;
    string s;
    while (getline(cin, s)) {
        total++;
        if(mp.find(s) == mp.end()) mp.insert({s, 1});
        else mp.find(s)->second++;
    }
    
    map<string, double>::iterator iter;
    //출력
    cout << fixed;
    cout.precision(4);
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        iter->second /= total;
        iter->second *= 100.0;
        cout << iter->first << " " << iter->second << '\n';
    }
    return 0;
}
