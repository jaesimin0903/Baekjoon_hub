#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<string> split(string str, char deli){
    istringstream iss(str);
    vector<string> res;
    string buf;
    
    while(getline(iss,buf,deli)){
        res.push_back(buf);
    }
    
    return res;
}

//유저는 한번에 한명 신고가능 (신고회수 제한 없음) , 동일한 유저에 대한 신고는 1번만
//k번 이상 신고 -> 게시판 이용 정지, 해당유저를 신고한 모든 유저에게 메일 전달
//unordered_map 을 이용해 신고회수 관리


unordered_map<string, unordered_set<string>> um;
unordered_map<string,int> name_map;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(int i = 0;i<id_list.size();i++){
        name_map.insert({id_list[0],0});
    }
    
    //신고당한 사람 키 : 신고한사람 집합 값
    for(auto &val : report){
        vector<string> res;
        res = split(val, ' ');
        
        um[res[1]].insert(res[0]);
    }
    
    //맵 순회하면서 set size 2 넘어가는 것들 체킹 (넘어가는 애들 신고하는 집합을 순회하면서 메시지 전송횟수 저장)
    for(auto &rep : um){
        if(rep.second.size() >= k){
            for(auto &name : rep.second){
                name_map[name]++;
            }
        }
    }
    
    for(int i =0;i<id_list.size();i++){
        answer.push_back(name_map[id_list[i]]);
    }
    
    return answer;
}