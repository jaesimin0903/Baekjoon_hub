#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<string> us;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for(int i =0;i<words.size();i++){
        string str = words[i];
        if(us.find(str) == us.end()){
            if(i != 0){
                if(str[0] != words[i-1][words[i-1].length()-1]){
                    answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
                }
            }
            us.insert(str);
        }
        else{
            answer.push_back(i%n+1);
            answer.push_back(i/n+1);
            return answer;
            break;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}