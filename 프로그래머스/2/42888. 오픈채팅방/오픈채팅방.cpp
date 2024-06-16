#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,string> um;

vector<string> split(string str, char deli){
    vector<string>res;
    string buf;
    istringstream iss(str);
    
    while(getline(iss,buf,deli)){
        res.push_back(buf);
    }
    
    return res;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> a;
    for(auto &val : record){
        vector<string> rec = split(val,' ');
        
        
        if(rec[0] == "Enter"){
            um[rec[1]] = rec[2];
            
            a.push_back({rec[1],"님이 들어왔습니다."});
        }else if(rec[0] == "Leave"){
            a.push_back({rec[1],"님이 나갔습니다."});
        }else{
            um[rec[1]] = rec[2];
        }
    }
    
    for(auto&val : a){
        
        answer.push_back(um[val.first] + val.second);
    }
    
    return answer;
}