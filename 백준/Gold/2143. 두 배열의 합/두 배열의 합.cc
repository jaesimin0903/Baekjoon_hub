#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll T;
int n,m;
int A[1010];
int B[1010];

ll ps_A[1010];
ll ps_B[1010];

unordered_map<ll, int> um;

int main() {
    cin >> T;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= n; i++) {
        ps_A[i] = A[i - 1] + ps_A[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        ps_B[i] = B[i - 1] + ps_B[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            //cout << ps_B[j] - ps_B[i - 1] << ' ';
            um[ps_B[j] - ps_B[i - 1]]++;
        }
    }
    //cout << '\n';
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ll target = T - (ps_A[j] - ps_A[i - 1]);
            //cout << target << ' ';
            if (um[target] > 0) {
                //cout << "ans " << ' ';
                ans+=um[target];
            }
        }
    }
    cout << ans;

    return 0;
}
