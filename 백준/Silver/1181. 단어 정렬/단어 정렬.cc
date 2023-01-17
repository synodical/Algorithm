// 결론: 우선순위 큐를 쓰니 코드도 간결하고 정말 이해가 쉽구나!!
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int INF = 1e6;
int n;
bool compare(string a, string b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

vector<string> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);
    cout << v[0] << '\n';
    for (int i = 1; i < v.size(); i++) {
        if(v[i-1] == v[i]) continue;
        cout << v[i] << '\n';
    }
    return 0;
}

