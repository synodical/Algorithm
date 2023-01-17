#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n, m, a;
vector<int> v;
int answer[10];
bool isused[10];

void solve(int level, int num) {
    if(level == m) {
        for(int i = 0; i < m; i++) cout << answer[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = num; i < n; i++) {
  //      if(isused[i] == true) continue;
    //    isused[i] = true;
        answer[level] = v[i];
        solve(level + 1, i);
   //     isused[i] = false;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    solve(0, 0);
}
