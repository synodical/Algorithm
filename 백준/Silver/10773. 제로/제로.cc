//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/04/03.
//

#include <iostream>
#include <stack>
using namespace std;
 
int sum = 0;

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k;
    cin >> k;
    
    stack<int> st;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        if(a) st.push(a);
        else st.pop();
    }
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}
