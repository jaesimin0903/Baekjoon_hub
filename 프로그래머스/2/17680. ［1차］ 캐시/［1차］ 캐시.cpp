#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

deque<string> dq;

string toLowerCase(string str){
    string tmp = "";
    for(int i =0;i<str.size();i++){
        tmp+=tolower(str[i]);
    }
    return tmp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for(int i =0;i<cities.size();i++){
        string city = toLowerCase(cities[i]);
        if(dq.size() < cacheSize){
            bool is_pushed = false;
            for(int j =0;j<dq.size();j++){
                if(dq[j] == city && !is_pushed){
                    //cout << cities[i] << "\n";
                    answer+=1;
                    //cout << "hit" << "\n";
                    dq.push_back(dq[j]);
                    dq.erase(dq.begin() +j);
                    is_pushed = true;
                }
            }
            if(!is_pushed){
                answer+=5;
                dq.push_back(city);
               
            } 
        }else if (dq.size() == cacheSize){
            bool is_pushed = false;
            for(int j =0;j<dq.size();j++){
                if(dq[j] == city&& !is_pushed){
                    answer+=1;
                    //cout << "hit" << "\n";
                    dq.push_back(dq[j]);
                    dq.erase(dq.begin() +j);
                    is_pushed = true;
                }
            }
            if(!is_pushed){
                answer+=5;
                dq.push_back(city);
                dq.pop_front();
            } 
        }
        for(int index = 0;index<dq.size();index++){
            //cout << dq[index] << " ";
        }
        //cout << "\n";
    }
    
    return answer;
}