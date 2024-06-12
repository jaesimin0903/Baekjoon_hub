#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(string s) {
    vector<int> ans;
    //주어진 집합의 사이즈 별로 정렬
    //작은 사이즈 부터 순서를 찾아가기
    vector<vector<int>> v;
    
    stack<char> st;
    string part = "";
    vector<int> part_vec;
    for(int i = 1;i<s.size()-1;i++){
        if(s[i] == '{'){
            st.push('{');
        }else if(!st.empty() && st.top() == '{' && s[i] == '}'){
            if(part != ""){
                part_vec.push_back(stoi(part));
                part = "";
            }
            v.push_back(part_vec);
            st.pop();
            part_vec.clear();
        }else if(!st.empty() && st.top() == '{'){
            if(s[i] == ','){
                part_vec.push_back(stoi(part));
                part = "";
            }else{
                part+=s[i];
            }
        }
    }
    
    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b){
       return a.size() < b.size(); 
    });
    
    for(auto & row : v){
        for(auto & val : row){
            if(ans.size() == 0){
                ans.push_back(val);
            }else{
                bool flag = false;
                for(int i = 0;i<ans.size();i++){
                    if(ans[i] == val) flag = true;
                }
                if(!flag) ans.push_back(val);
            }
        }
    }
    
    return ans;
}