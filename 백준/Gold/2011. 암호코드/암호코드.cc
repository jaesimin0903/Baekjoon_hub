#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <deque>
#include <tuple>
#include <utility>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

int N , Q, L,M,T;
int rest = 1000000;
ll dp[2000010];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    dp[0] = 1;
    dp[1] = 1;
    if(str[0] == '0'){
        cout << 0;
        return 0;
    }
    //dp[2] = dp[1] + dp[0](if idx 1~2 lower than 27)
    //11201 1 1 20 1, 11 20 1
    for(int i = 1;i<str.size();i++){
        int one = str[i] - '0';
        int ten = str[i-1] -'0';
        int number = ten * 10 + one;
        //cout << ten << " " << one << " "<< number <<'\n';

        if(str[i] == '0'){
            if(number > 26 || number == 0){
                cout << 0;
                return 0;
            }else{
                dp[i+1] = dp[i];
                continue;
            }
        }else if(str[i-1] == '0'){
            dp[i+1] = dp[i];
            continue;
        }else if(i+1 <= str.size() && str[i+1] == '0'){
            dp[i+1] = dp[i];
            continue;
        }
        
        if(number > 26){
            dp[i+1] =(dp[i+1] + dp[i] )% rest;
        }else{
            dp[i+1] = (dp[i+1] + dp[i] + dp[i-1]) %rest;
        }
    }

    for(int i =1;i<=str.size();i++){
        //cout << dp[i] << " ";
    }
    cout << dp[str.size()];
    return 0;
}