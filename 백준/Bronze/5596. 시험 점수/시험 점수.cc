#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int MAX = 100002;
int main(){
    int ming[4], man[4], minsum = 0, mansum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> ming[i];
        minsum += ming[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> man[i];
        mansum += man[i];
    }
    cout << max(minsum, mansum);
}

