#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector<int> v;
    int n;
    cin >> n;
    for( int i = 0; i <n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for(int i =0; i < n; i++)
    {cout << v[i] << '\n';}
    
return 0;
}