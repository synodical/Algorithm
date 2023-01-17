#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
#define MAX 51

int root, leaf, d;
vector<vector<int>> tree; // 2차원 벡터 tree
int visit[MAX];

void dfs(int x) {
    int child = 0;
    int _size = tree[x].size();
    for(int i = 0; i < _size; i++) {
        int cur = tree[x][i];
        if(cur == d) continue;
        dfs(cur);
        child++; // 부모가 x인 행의 배열의 size가 child의 개수
    }
    if(!child) leaf++; // child == 0 이면 leaf 노드이다
}

int main() {
    int N;
    cin >> N;
    tree = vector<vector<int>>(N);
    for(int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if(p == -1) {
            root = i;
            continue;
        }
        tree[p].push_back(i);
    }
    
    cin >> d;
    
    if(root == d)
        cout << "0";
    else {
        dfs(root);
        cout << leaf;
    }
    return 0;
}
