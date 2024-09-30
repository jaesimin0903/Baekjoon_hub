#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = 1e14;
    
    while(left <= right){
        long long mid = (left+ right)/2;
        
        long long  tmp = 0;
        for(auto time : times){
            tmp+=mid/time;
        }
        
        if(tmp >= n){
            answer = mid;
            right = mid -1;
        }else{
            left = mid +1; 
        }
    }
    
    return answer;
}

