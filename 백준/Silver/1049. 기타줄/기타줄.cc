#include <iostream>
#include <vector>
#include <deque>
#include<unordered_set>
#include<algorithm>
#include<string>
#include <cmath>
using namespace std;

typedef long long ll;

int N, M;

int set[110];
int one[110];

int main() {
    
    cin >> N >> M;
    for(int i =0;i<M;i++){
        cin >> set[i];
        cin >> one[i];
        
    }

    sort(set,set+M);
    sort(one,one+M);
    
    int ans = 0;

    if(N <=6){
        if(set[0] < one[0] * (N)){
            ans += set[0];
        }else{
            ans += one[0] * N;
        }
    }else{
        if(N % 6 != 0){
            //모두 세트 || 모두 낱개 || 세트와 낱개 
            ans += min(set[0] * (N/6 + 1), min(N*one[0], (N/6) * set[0] + (N%6) * one[0]));
        }else{
            ans += min(set[0] * (N/6), min(N*one[0], (N/6) * set[0] + (N%6) * one[0]));
        }
    }
    cout << ans ;

    return 0;
}
