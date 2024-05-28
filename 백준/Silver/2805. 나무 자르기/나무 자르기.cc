#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;
int N, M;
ll arr[1000010];

int main() {

    cin >> N >> M;

    for(int i =0;i<N;i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    ll s = 0;
    ll e = arr[N-1];
    ll mid = (s+e) /2;
    ll ans = 0;
    while(s <= e){
        mid = ( s + e)/2;
        ll sum = 0;
        //cout << mid << "\n";
        for(int i = 0;i<N;i++){
            if(arr[i] - mid > 0) sum += arr[i] - mid;
        }
        if(sum >= M ){ s = mid + 1; ans = mid;}
        else if(sum < M ) e = mid -1;

    }

    cout << ans;
	
	return 0;
}