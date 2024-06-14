#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//중복 번호를 방지하기 위한 집합사용
//번호별 입출차시간 기록할 맵사용
//맵의 벡터 크기가 2보다 작으면 2359분 출차를 이용한 값계산
//값계산을 위한 맵

unordered_map <string , vector<string>> um;
unordered_set <string> us;
unordered_map<string, int> price; 

vector<string> split(string str, char deli){
    istringstream iss(str);
    string buf;
    vector<string> res;
    
    while(getline(iss,buf,deli)){
        res.push_back(buf);
    }
    
    return res;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(auto &record : records){
        vector<string> r = split(record, ' ');
        
        //차량번호별 시간 입력
        um[r[1]].push_back(r[0]);
        //집합에 차량번호 추가
        us.insert(r[1]);
    }
    
    for(auto &record : um){
        int total =0;
        
        if(record.second.size() % 2 == 0){
            int out_time_hour, out_time_min;
            int in_time_hour, in_time_min;
            for(int i = 0;i<record.second.size();i+=2){
                string out_time = record.second[i+1];
                string in_time = record.second[i];

                out_time_hour = stoi(out_time.substr(0,2));
                out_time_min = stoi(out_time.substr(3,2));
                in_time_hour = stoi(in_time.substr(0,2));
                in_time_min = stoi(in_time.substr(3,2));


                if(in_time_min > out_time_min){
                    out_time_hour--;
                    out_time_min += 60;
                    total += out_time_min - in_time_min + (out_time_hour - in_time_hour) * 60;
                }else{
                    total += out_time_min - in_time_min + (out_time_hour - in_time_hour) * 60;
                }
            }
            
        }else{
            int out_time_hour, out_time_min;
            int in_time_hour, in_time_min;
            for(int i = 0;i<record.second.size()-1;i+=2){
                string out_time = record.second[i+1];
                string in_time = record.second[i];

                out_time_hour = stoi(out_time.substr(0,2));
                out_time_min = stoi(out_time.substr(3,2));
                in_time_hour = stoi(in_time.substr(0,2));
                in_time_min = stoi(in_time.substr(3,2));


                if(in_time_min > out_time_min){
                    out_time_hour--;
                    out_time_min += 60;
                    total += out_time_min - in_time_min + (out_time_hour - in_time_hour) * 60;
                }else{
                    total += out_time_min - in_time_min + (out_time_hour - in_time_hour) * 60;
                }
            }
            string in_time = record.second[record.second.size()-1];
            in_time_hour = stoi(in_time.substr(0,2));
            in_time_min = stoi(in_time.substr(3,2));
            total += 59 - in_time_min + (23 - in_time_hour) * 60;
        }
        int val = fees[1];
        if(total > fees[0]){
            int rest = total - fees[0];
            int a = rest / fees[2];
            if(rest%fees[2] != 0) a++;
            val += fees[3] * a;
        }
        price[record.first] = val;
    }
    
    vector<pair<int,int>> ans;
    
    for(auto & val : price){
        ans.push_back({stoi(val.first), val.second});
    }
    
    sort(ans.begin(), ans.end());
    
    for(auto &val : ans){
        answer.push_back(val.second);
    }
    
    return answer;
}