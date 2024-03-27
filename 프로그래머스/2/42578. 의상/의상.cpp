#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> um;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i = 0;i<clothes.size();i++){
        um[clothes[i][1]]++;
    }
    
    
    for(auto v : um){
        answer *= v.second +1;
    }

    
    answer-=1;
    
    return answer;
}