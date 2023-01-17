#include <iostream>
using namespace std;
const int MAX = 1001;
int sum=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum+=a;
    }
    if (sum > n/2) {
        cout << "Junhee is cute!";
    }
    else cout << "Junhee is not cute!";
    return 0;
}