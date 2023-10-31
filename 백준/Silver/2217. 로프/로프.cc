#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



int main() {

	int n;
	cin >> n;

	int sum = 0;

	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());



	for (int i = 0; i <v.size(); i++) {
		if (v[i] *( v.size()-i)>sum) {
			sum = v[i] * (v.size()-i);
		}
	}
	cout << sum;
	return 0;
}


