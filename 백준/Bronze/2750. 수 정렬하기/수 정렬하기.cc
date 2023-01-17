#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int low, int high) {
    int pivot = low;
    int i = low + 1; int j = high;
    while (1) {
        while(v[i] <= v[pivot] && i <= high) i++;
        while(v[j] > v[pivot] && j > low) j--;
        if(i < j) Swap(&v[i], &v[j]);
        else break;
    }
    Swap(&v[pivot], &v[j]);
    return j;
}

void quicksort(int l, int h) {
    int p;
    if(l < h) {
        p = partition(l, h);
        quicksort(l, p - 1);
        quicksort(p + 1, h);
    }
}

int main() {
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    quicksort(0, n - 1);
    for(int i = 0; i < n; i++) {
        cout << v[i] << endl;
    }
    return 0;
}

