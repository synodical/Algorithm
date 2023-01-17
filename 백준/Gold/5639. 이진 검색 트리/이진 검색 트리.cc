// 왜지... 왜
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL; // 루트 노드는 NULL 초기화

/* BST를 구현한 add함수 */
void add(int num) {
    Node *p, *q = NULL, *r = NULL; // aux pointer
    p = root;
    /* BST의 추가 지점까지 쫓아감 */
    while (p != NULL) {
        if(num <= p->data) {
            r = p;
            p = p->left;
        }
        else {
            r = p;
            p = p->right;
        }
    }
    /* new node q 할당 */
    q = new Node();
    if(q == NULL) return; // 메모리 x -> return
    
    q->data = num; // q의 data를 저장하고 좌우 포인터는 접지
    q->left = NULL;
    q->right = NULL;
    
    if(root == NULL) // BST에 노드가 한개도 없는 경우
        root = q;
    else if(num <= r->data)
        r->left = q;
    else r->right = q;
}

void postorder(Node* node) {
    if(node == NULL) cout << "wrong add";
    if (node->left != NULL)
        postorder(node->left);
    if (node->right != NULL)
        postorder(node->right);
    cout << node->data << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int val;
    while (cin >> val) {
        if (val == EOF) break;
        add(val);
    }
    if(root == NULL) cout << "wrong add";
    postorder(root);
    return 0;
}
