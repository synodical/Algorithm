#include <iostream> 
using namespace std; 
int chess[6] = { 1, 1, 2, 2, 2, 8 }; 
int main(void) { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    for (int i = 0; i < 6; i++) { 
        int cnt; 
        cin >> cnt; 
        cout << chess[i] - cnt << ' '; 
    } 
    cout << '\n'; 
    return 0; 
}

