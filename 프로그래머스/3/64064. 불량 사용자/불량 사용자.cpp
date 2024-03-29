#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;

//banned_id 원소만큼 벡터 생성
//banned_id의 원소와 짝을 이루는 user 벡터에 삽입
//생성된 벡터 배열을 이용한 dfs
//visited 이용해서 중복 처리


vector<vector<int>> v;
vector<vector<int>> ans;
bool visited[9];

void dfs(int idx,vector<int> vec){
    if(idx == v.size()){
        sort(vec.begin(),vec.end());
        ans.push_back(vec);
        
        return;
    }        
    
    for(int i =0;i<v[idx].size();i++){
        if(!visited[v[idx][i]]){
            visited[v[idx][i]] = 1;
            vec.push_back(v[idx][i]);
            dfs(idx+1,vec);
            vec.pop_back();
            visited[v[idx][i]] = 0;
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    
    for(int i =0;i<banned_id.size();i++){
        vector<int> vv;
        v.push_back(vv);
    }
    
    for(int i =0;i<user_id.size();i++){
        for(int j =0;j<banned_id.size();j++){
            bool is_ok = true;
                if(user_id[i].size() == banned_id[j].size()){
                        for(int k = 0;k<banned_id[j].size();k++){
                            //제외대상 확인
                            if(banned_id[j][k] != '*' && banned_id[j][k] != user_id[i][k])   is_ok =false;
                        }
                                //제외대상이면
            if(is_ok)v[j].push_back(i);
                }

            }
        }
    // for(auto row : v){
    //     for(auto val : row){
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }
    vector<int> vec;
    dfs(0,vec);
    
    // for(auto row : ans){
    //     for(auto val : row){
    //         cout << val << " ";
    //     }
    //     cout << "\n";
    // }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    answer = ans.size();
    return answer;
}