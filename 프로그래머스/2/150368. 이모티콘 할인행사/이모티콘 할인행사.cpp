#include <string>
#include <vector>
#include <iostream>

//이모티콘 플러스 서비스 가입자 최대
//판매액 최대

//n명 m개 할인

//구매하는 이모티콘 값이 플러스 값보다 늘어나면 플러스 가입

//할인율은 10 20 30 40 으로 무작위 설정되므로 이모티콘 7종에 대한 할인율을 랜덤 적용(dfs)
//각 할인율 조합에 따라 유저별 임티 플러스 활성화 가능 여부와 이모티콘 판매액 구하기
//가장 큰 이용자수 일 때 최신화, 같은 이용자수이면 값 최신화
using namespace std;

int price[7];
int leng;

vector<int> emo;
vector<vector<int>> u;

int max_user = 0;
int max_price = 0;
void dfs(int cnt){
    if(cnt == leng){
        //유저별 이모티콘 계산
        
        int plus_user = 0;
        int total = 0;
        
        for(auto & user : u){
            int sum = 0;
            
            for(int i = 0;i<leng;i++){
                if(price[i] >= user[0]){
                    sum += emo[i] * (100- price[i]) / 100;
                }
            }
            
            if(sum >= user[1]){
                plus_user++;
            }else{
                total += sum;
            }
            
            //cout << user[0]<< ' '<< plus_user << ' ' << sum << "\n";
        }
        
        if(max_user < plus_user){
            max_user = plus_user;
            max_price = total;
            //cout << "update " << max_user << ' ' << max_price << "\n";
        }else if(max_user == plus_user){
            if(max_price < total) max_price = total;
        }
        
        return ;
    }
    
    for(int i = 10;i<=40;i+=10){
        price[cnt] = i;
        dfs(cnt + 1);
        price[cnt] = 0;
    }
}



vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    emo = emoticons;
    leng = emoticons.size();
    u = users;
    
    for(int i = 10;i<=40;i+=10){
        price[0] = i;
        dfs(1);
        price[0] = 0;
    }
    answer.push_back(max_user);
    answer.push_back(max_price);
    //서비스 가입자수, 판매액
    return answer;
}