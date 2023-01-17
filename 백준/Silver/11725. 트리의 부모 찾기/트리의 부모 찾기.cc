#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100001
vector<int> tree[MAX];
bool visited[MAX];
int parent[MAX];

void dfs(int x) {
    visited[x] = true;
    int _size = tree[x].size(); // size == num of children
    for(int i = 0; i < _size; i++) {
        int cur = tree[x][i]; // 자식노드로 넘어감
        if(!visited[cur]) { // 부모노드를 확인한 경우, cur이 자식노드인 경우
            parent[cur] = x;
            dfs(cur);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    parent[1] = -1;
    dfs(1); // 루트 == 1
    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";

    return 0;
}

