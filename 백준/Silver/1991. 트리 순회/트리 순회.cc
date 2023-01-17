#include <iostream>

using namespace std;
char tree[26][2] = {'.', };


void preorder(char root) { // VLR
    if(root == '.') return;
    else {
        cout << root;
        preorder(tree[root-'A'][0]);
        preorder(tree[root-'A'][1]);
    }
}

void inorder(char root) { // LVR
    if(root == '.') return;
    else {
        inorder(tree[root-'A'][0]);
        cout << root;
        inorder(tree[root-'A'][1]);
    }
}

void postorder(char root) { // LRV
    if(root == '.') return;
    else {
        postorder(tree[root-'A'][0]);
        postorder(tree[root-'A'][1]);
        cout << root;
    }
    // 바보.. 출력 형식...
}

int main() {

    int n, i;
    char root, left, right;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> root >> left >> right;
        tree[root-'A'][0] = left; // 배열 index는 int이므로 root - 'A', ascii code
        tree[root-'A'][1] = right;
    }
    preorder('A'); cout << '\n';
    inorder('A'); cout << '\n';
    postorder('A'); cout << '\n';
    return 0;
}
