#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;
int N, M;
int arr[110][10010];

int bs(vector<int> &v, int x){
    int s = 0;
    int e = v.size()-1;
    int mid = (s+e)/2;

    while(s <= e){
        mid = (s+e)/2;
        if(v[mid] > x){
            e = mid-1;
       }else if(v[mid] <x){
            s = mid + 1;
       }else{
        break;
       }
    }
    return mid;
}

int main() {

    cin >> M >> N;
    int ans = 0;

    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0;i<M;i++){
        vector<int> v;
        for(int j = 0;j<N;j++){
            v.push_back(arr[i][j]);
        }
        sort(v.begin(), v.end());
        for(int j = 0;j<N;j++){
            arr[i][j] = bs(v,arr[i][j]);
        }
    }

    for(int i = 0;i<M;i++){
        for(int j = i+1;j<M;j++){
            bool is_ok = true;
            for(int k = 0;k<N;k++){
                if(arr[i][k] != arr[j][k]){ is_ok = false;break;}
            }
            if(is_ok) ans +=1;
        }
    }

    cout << ans;

	
	return 0;
}