#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



int main() {

	int n;
	cin >> n;

	int sum = 0;

	//홀수 -5
	//짝수 & 10배수 -5
	//짝수 -2
	while (n > 1) {
		if (n % 2 == 1 && n >= 5) {
			n -= 5;
			sum++;
		}
		else if (n % 2 == 0 && n % 10 == 0) {
			n -= 5;
			sum++;
		}
		else if (n % 2 == 0) {
			n -= 2;
			sum++;
		}
		else if (n == 3) {
			cout << -1;
			return 0;
		}
	}
	if (sum != 0)
		cout << sum;
	else
		cout << -1;
	return 0;
}


