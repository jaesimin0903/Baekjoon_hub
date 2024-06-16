#include <iostream>
#include <vector>
#include <deque>
#include<unordered_set>
#include<algorithm>
#include<string>
#include <cmath>
using namespace std;

typedef long long ll;


int main() {
    
    while(1){
        string s;
        cin >> s;
        if(s == "0") break;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            int n = s[i] - '0';
            int ns = n * (pow(2,s.size()-i)-1);
            ans += ns;
        }

        cout << ans << '\n';
    }


    return 0;
}
