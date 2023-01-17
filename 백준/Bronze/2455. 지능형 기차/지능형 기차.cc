#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1001;
int in, out, Max = 0;
int train[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    for (int i = 0; i < 4; i++) {
        cin >> out >> in;
        train[i] = train[i-1] + in - out;
        Max = max(train[i], Max);
    }
    cout << Max;
    return 0;
}
