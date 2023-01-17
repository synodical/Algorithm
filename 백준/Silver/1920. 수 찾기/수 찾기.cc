#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> N, M;
int n, m, a, b;

void bs(int key) {
    int i = 0; int j = n - 1;
    while(i <= j) {
        int mid;
        mid = (i + j) / 2;
        
        if(key < N[mid]) {
            j = mid - 1;
        }
        else if(key > N[mid]) {
            i = mid + 1;
        }
        else {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        N.push_back(a);
    }
    sort(N.begin(), N.end());
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> b;
        bs(b);
    }
    return 0;
}

