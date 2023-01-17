#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int MAX = 100001;
int n, inorder[MAX], postorder[MAX], memo[MAX];

void preorder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end)
        return;
    
    int root = postorder[post_end];
    cout << root << " ";
    
    int idx = memo[root]; // inorder에서 현재 root index
    int left = idx - in_start;
    
    preorder(in_start, idx - 1, post_start, post_start + left - 1);
    preorder(idx + 1, in_end, post_start + left, post_end - 1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> inorder[i];

    for (int i = 1; i <= n; i++)
        cin >> postorder[i];

    // 인오더의 해당 값 인덱스 기록하는 배열
    for (int i = 1; i <= n; i++)
        memo[inorder[i]] = i;
    preorder(1, n, 1, n);
    return 0;
}
