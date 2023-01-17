#include <iostream> 
using namespace std;
int main() { 
    int a, b, c, hour, min, end_m;
    cin >> a >> b;
	cin >> c;
    hour = c / 60;
    min = c % 60;
	end_m = b + min;
	if (b + min >= 60) {
		hour++;
		end_m -= 60;
	}
    cout << (a + hour) % 24 << " " << end_m;
    return 0; 
}
