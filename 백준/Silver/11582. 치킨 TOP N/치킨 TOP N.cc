#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int n, k;
int v[1<<20];
int sorted[1<<20];

void Merge(int v[], int l, int r) {
    if ((r-l) > n/k) { // r-l== 합병하려는 배열 인덱스 범위
        return;
    }
    int m = (l+r)/2;
    int i = l, j = m+1;
    int k = 0;
    while (i <= m && j <= r) {
        if (v[i] < v[j]) {
            sorted[k++] = v[i++];
        }
        else {
            sorted[k++] = v[j++];
        }
    }
    while (i <= m) {
        sorted[k++] = v[i++];
    }
    while (j <= r) {
        sorted[k++] = v[j++];
    }
    for (i = l; i <= r; i++) {
        v[i] = sorted[i - l];
    }
}
void mergeSort(int v[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        Merge(v, l, r);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cin >> k;
    
    mergeSort(v, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}

