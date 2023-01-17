#include <iostream>
#include <algorithm>
#include <string>
#define INF 987654321
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x,y,tx,ty=0;
    cin >> x >> y;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= y) {
            ty++;
        }
    }
    tx = n * x / 100;
    cout << tx << " " << ty;
    return 0;
}
