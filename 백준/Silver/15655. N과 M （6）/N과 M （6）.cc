#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M, a;
vector<int> v;
int answer[8];
bool isused[8];

void solve(int level, int num) {
    if(level == M) {
        for(int i = 0; i < M; i++) cout << answer[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = num; i < N; i++) {
        if (isused[i])continue;
        isused[i] = true;
        answer[level] = v[i];
        solve(level + 1, i);
        isused[i] = false;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    solve(0, 0);
}

