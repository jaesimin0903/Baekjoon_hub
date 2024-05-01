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

int N, K;

ll arr[200010];
ll cnt[100010];
ll m[510][510];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int s = 0;
    int e = 0;
    int size = 1;
    cnt[arr[0]]++;
    while (s <= e && s!=N-1) {
        if (cnt[arr[e + 1]] + 1 > K || e == N-1) {
            if (s == e) {
                cnt[arr[s]]--;
                s++;
                cnt[arr[e+1]]++;
                e++;
            }
            else {
                cnt[arr[s]]--;
                s++;
            }
        }
        else if(e+1 <= N-1){
            cnt[arr[e + 1]]++;
            e++;
        }
        //cout << s << " " << e << "\n";
        size = max(e - s+1, size);
    }

    cout << size;
    return 0;
}
