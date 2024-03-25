#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_set<int> us;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
unordered_map<int, int> cnt;
    
    
    for(int i =0;i<tangerine.size();i++){
        cnt[tangerine[i]]++;
    }
    
    auto cmp = [&cnt](int a, int b){
        return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a > b);
    };
    
    sort(tangerine.begin(), tangerine.end(), cmp);
    
    for(int i =0;i<k;i++){
        //if(us.size() >= k) break;
        
        us.insert(tangerine[i]);
        //cout << tangerine[i] << " " << us.size()<<"\n";
        
    }
    
    answer = us.size();
    
    return answer;
}