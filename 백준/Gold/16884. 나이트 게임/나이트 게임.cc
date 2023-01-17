#include <iostream>
using namespace std;
int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n %2==0) {
            cout << "cubelover\n";
        }
        else cout << "koosaga\n";
    }
    
    return 0;
}