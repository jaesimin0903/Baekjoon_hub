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
#include<iomanip>
using namespace std;

typedef long long ll;

int N, K;

ll arr[200010];
//ll cnt[100010];
ll m[510][510];

map<string, int> cnt;
int total = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str = "";

    while (getline(cin, str)) {
        if (str.empty()) {
            break;
        }
        ++cnt[str];
        total++;
    }

    for (auto& v : cnt) {
        cout << v.first << " " << fixed << setprecision(4) << (v.second * 100.0 / total) << '\n';
    }
    
    return 0;
}
