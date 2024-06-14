#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cmath>

using namespace std;

typedef long long ll;

bool is_prime(string num){
    if(num.empty()) return false;
    ll n = stoll(num);
    if(n < 2) return false;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

vector<string> split( string str, char deli){
    istringstream iss(str);
    string buf;
    vector<string> res;
    
    while(getline(iss,buf,deli)){
        res.push_back(buf);
    }
    
    return res;
}

//숫자를 k진수로 바꾸기
string convert(ll n, ll k){
    string res = "";
    
    while(n/k >= 1){
        res = to_string(n % k) + res;
        n /= k;
    }
    
    res = to_string(n) + res;
    
    return res;
}

int solution(int n, int k) {
    int answer = 0;
    
    ll N = n;
    ll K = k;
    
    string convert_num = convert(N,K);
    
    cout << convert_num;
    
    vector<string> arr = split(convert_num, '0');
    
    for(auto & val : arr){
        if(is_prime(val))answer++;
    }
    
    return answer;
}