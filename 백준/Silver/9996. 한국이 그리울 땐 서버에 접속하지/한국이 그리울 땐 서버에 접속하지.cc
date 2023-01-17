#include <iostream>
#include <string>
#include <regex>
#include <vector>
using namespace std;

int main(void){
    int t;
    cin >> t;
    string a;
    cin >> a;
    a.replace(a.find('*'), 1, "\\w*");
    while (t--) {
        string s;
        cin >> s;
        cout << (regex_match(s,regex(a)) ? "DA\n" : "NE\n");
    }
    return 0;
}