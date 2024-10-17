#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip> // setprecision 사용을 위해 필요

using namespace std;
typedef long double ll;
int N;

int main() {
	cin >> N;
	vector<pair<ll, ll>> v;

	// 그래프 입력
	for (int i = 0; i < N; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	ll rootX = v[0].first;
	ll rootY = v[0].second;

	ll ans = 0;

	for (int i = 1; i < N - 1; i++) {
		ll c = v[i].first;
		ll d = v[i].second;
		ll e = v[i + 1].first;
		ll f = v[i + 1].second;

		
		ans += (rootX * d + c * f + e * rootY - c * rootY - e*d - rootX * f)/2;
	}

	// 소수 둘째 자리에서 반올림 및 출력
	cout << fixed << setprecision(1) << abs(ans) << endl;

	return 0;
}
