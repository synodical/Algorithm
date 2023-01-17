//
//  main.cpp
//  boj
//
//  Created by LeeYeEun on 2021/07/17.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Person{
    string name;
    int kor, eng, math;
};

bool cmp(Person &u, Person &v){
    if(u.kor > v.kor) // 1
        return true;
    else if(u.kor == v.kor) { // 2
        if (u.eng < v.eng)
            return true;
        else if(u.eng == v.eng) {
            if (u.math > v.math)
                return true;
            else if (u.math == v.math)
                return u.name < v.name;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t;
    cin >> t;

    vector<Person> v(t);

    for (int i = 0; i < t; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < t; i++)
        cout << v[i].name << '\n';
    return 0;
}
