#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i =left;i<=right;i++){
        long long x = i/n;
        long long y = i%n;
        long long val = max(x,y);
        answer.push_back(val+1);
    }
    
    return answer;
}