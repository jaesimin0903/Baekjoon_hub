#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include<cstring>
using namespace std;

typedef long long ll;

int N;
ll C;

unordered_map<ll, int> mp;
vector<pair<ll, int>> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        auto it = find_if(v.begin(), v.end(), [n](const auto& a) {
            return a.first == n;
            });

        if (it != v.end()) {
            it->second++;
        }
        else {
            v.push_back({ n,1 });
        }
    }

 

    stable_sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;

        });

    for (auto val : v) {
        for (int i = 0; i < val.second; i++) {
            cout << val.first << " ";
        }
    }

    return 0;
}

