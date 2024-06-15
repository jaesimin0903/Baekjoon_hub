#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int arr[110][110];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int num = 1;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            arr[i][j] = num;
            num++;
        }
    }
    
    vector<deque<int>> v;
    for(auto & query : queries){
        int minn = 100000;
        for(int i = query[0]-1;i<=query[2]-1;i++){
            deque<int> dq;
            
            for(int j = query[1]-1;j<=query[3]-1;j++){
                
                dq.push_back(arr[i][j]);    
            }
            v.push_back(dq);
        }
        
        for(int i = 0;i<v.size();i++){
            for(int j =0;j<v[i].size();j++){
            }
        }
        
        //rotate
        for(int i = v.size()-2;i>=0;i--){
            int tmp = v[i].back();
            v[i].pop_back();
            v[i+1].push_back(tmp);
        }
        for(int i = 1;i<v.size();i++){
            int tmp = v[i].front();
            v[i].pop_front();
            v[i-1].push_front(tmp);
        }
        

        
        for(int i = 0;i<v.size();i++){
            for(int j = 0;j<v[i].size();j++){
                arr[query[0]-1+i][query[1]-1+j] = v[i][j];
            }
        }
        
        for(int i = 0;i<v.size();i++){
            for(int j =0;j<v[i].size();j++){
                if(i==0 || i==v.size()-1){
                    minn = min(minn,v[i][j]);
                }else{
                    if(j==0 || j== v[i].size()-1){
                        minn = min(minn,v[i][j]);
                    }
                }
            }
        }
        v.clear();
        answer.push_back(minn);
    }
    
    return answer;
}