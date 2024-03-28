#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string,int> item;
unordered_map<string,int> shop;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i =0;i<want.size();i++){
        item[want[i]] = number[i];
    }
    
    for(int i =0;i<10;i++){
        shop[discount[i]]++;
    }
    
    for(int i =0;i<discount.size() -9;i++){
        if(i!=0){
         shop[discount[i-1]]--;
        shop[discount[i+9]]++;   
        }
            bool is_ans = true;
        

            for(int k = 0;k<want.size();k++){
                if(item[want[k]] != shop[want[k]]){
                    is_ans = false;
                }
            }
        
            if(is_ans){
                
                answer++;
                
            } 
        
    }
    
    return answer;
}