#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



int main() {

	int n;
	cin >> n;

	int sum = 0;

	vector<double> v;
	
	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	double max = v[v.size() - 1];

	for (int i = 0; i < n-1; i++) {
		max += v[i] / 2;
	}

	cout << max;
	return 0;
}


