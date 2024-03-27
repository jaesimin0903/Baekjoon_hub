#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string,int> us;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(auto name : participant){
        us[name]++;
    }
    
    for(auto name : completion){
        us[name]--;
    }
    
    for(auto pair : us){
        if(pair.second == 1){
            answer = pair.first;
        }
    }
    
    
    return answer;
}