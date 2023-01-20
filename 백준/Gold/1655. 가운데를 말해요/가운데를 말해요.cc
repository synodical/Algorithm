#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<>> min_pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (i == 0) {
            max_pq.push(a);
            cout << max_pq.top() << '\n';
            continue;
        }
        if (min_pq.size() + 1 == max_pq.size()) {
            min_pq.push(a);
        } else if (min_pq.size() == max_pq.size()) {
            max_pq.push(a);
        }
        
        if (max_pq.top() > min_pq.top()) {
            int min_top = min_pq.top();
            int max_top = max_pq.top();
            min_pq.pop();
            max_pq.pop();
            min_pq.push(max_top);
            max_pq.push(min_top);
        }
        cout << max_pq.top() << '\n';
    }
    return 0;
}
