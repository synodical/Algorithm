
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
const int MAX = 10001;
struct oj {
    int age, join;
    string name;
    bool operator< (const oj &mem) const {
        return age < mem.age;
    }
};
vector<oj> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; string s;
        cin >> a; cin >> s;
        v.push_back(oj{a,i,s});
    }
    stable_sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i].age << " " << v[i].name << '\n';
    }
    return 0;
}
