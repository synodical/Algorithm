#include <iostream> 
using namespace std; 
int main(void) { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n; 
    cin >> n; 
    cout << (n/2+1) * ((n-n/2)+1) << '\n';
    return 0; 
}
