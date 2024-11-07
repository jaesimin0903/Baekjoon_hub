#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	int N;
	vector<ll> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll n;
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	ll closest_sum = 3e10;
	vector<ll> result(3);

	for (int i = 0; i < N - 2; i++) {
		int left = i + 1;
		int right = N - 1;

		while (left < right) {
			ll sum = arr[i] + arr[left] + arr[right];

			if (abs(sum) < abs(closest_sum)) {
				closest_sum = sum;
				result = { arr[i], arr[left], arr[right] };
			}

			if (sum < 0) {
				left++;
			}
			else if (sum > 0) {
				right--;
			}
			else {
				break;  // 정답이 0일 경우 바로 종료
			}
		}
	}

	sort(result.begin(), result.end());

	for (auto v : result) {
		cout << v << " ";
	}

	return 0;
}
