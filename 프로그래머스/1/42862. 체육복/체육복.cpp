#include <string>
#include <vector>
#include <iostream>
using namespace std;

//앞번호 혹은 뒷번호의 학생들에게만 체육복빌렺루수있음
//최대한 많은 학생이 체육
//reserve 와 lost에 중복된 학생이 나올 수 있음

//reserve 에 있는 번호와 lost의 있는 번호가 같거나 +1 | -1 이면 ++
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> num ;
    for(int i = 0;i<n;i++){
        num.push_back(1);
    }
    for(int i = 0;i<reserve.size();i++){
        num[reserve[i]-1]++;
    }
    for(int i = 0;i<lost.size();i++){
        num[lost[i]-1]--;
    }

       for(int i = 0;i<num.size();i++){
        cout << num[i] << " ";
    }
    
    //210210
    
    for(int i = 0;i<num.size();i++){
        if(num[i] == 2){
            if(i == 0){
                if(num[i+1]==0){
                    num[i]--;
                    num[i+1]++;
                }
            }else if(i == num.size()-1){
                if(num[i-1]==0){
                    num[i]--;
                    num[i-1]++;
                }
            }else{
                if(num[i-1]==0){
                    num[i]--;
                    num[i-1]++;
                }
                if(num[i]==2&& num[i+1]==0){
                    num[i]--;
                    num[i+1]++;
                }
            }    
        }
        
    }
    for(int i = 0;i<num.size();i++){
        if(num[i] >= 1) answer++;
    }
    
        for(int i = 0;i<num.size();i++){
        cout << num[i] << " ";
    }
    return answer;
}