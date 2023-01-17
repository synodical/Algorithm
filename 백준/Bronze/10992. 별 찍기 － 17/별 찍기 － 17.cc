// boj 10992.cpp
// https://lesslate.github.io/onlinejudge/Baekjoon-10992%EB%B2%88/ 참고
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int j = 1; j <= n - 1; j++){
		cout << " ";
	}
	cout << "*" << '\n';

	if (n > 1){
		for (int i = 2; i <= n - 1; i++)
		{
			for (int j = i; j <= n - 1; j++)
			{
				cout << " ";
			}
			cout << "*";
			for (int j = 1; j <= i * 2 - 3; j++)
			{
				cout << " ";
			}
			cout << "*" << '\n';
		}


		for (int j = 1; j <= n * 2 - 1; j++){
			cout << "*";
		}

	}
}