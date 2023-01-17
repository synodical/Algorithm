#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#define all(v) v.begin(),v.end()

using namespace std;
using ll = long long;
ll n, m, a, b, c, d, ans;
ll pre[1025][1025];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a;
			pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + a;
		}
	while (m--) {
		cin >> a >> b >> c >> d;
		cout << pre[c][d] - pre[a - 1][d] - pre[c][b - 1] + pre[a - 1][b - 1] << '\n';
	}
}
