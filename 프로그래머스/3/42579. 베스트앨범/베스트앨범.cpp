#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <tuple>

//1. 장르별 해시맵 생성하고 가장 많이 플레이한 장르를 순서대로 정렬
//2. 장르 순위별로 정렬하되 곡의 플레이 순서 정렬
using namespace std;

unordered_map<string, int> um;
vector<tuple<string,int,int> > v;

bool cmp(tuple<string,int,int> &a, tuple<string,int,int> &b){
    int ab,ac,bb,bc;
    string aa, ba;
    tie(aa,ab,ac) = a;
    tie(ba,bb,bc) = b;
    if(aa == ba) return ab > bb;
    return um[aa] > um[ba];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i =0;i<genres.size();i++){
        um[genres[i]]+=plays[i];
    }
    
    for(int i = 0;i<genres.size();i++){
        v.push_back({genres[i],plays[i],i});
    }
    
    sort(v.begin(),v.end(),cmp);
    string last_genre = "";
    int cnt = 0;
    for(auto val : v) {
        string current_genre = get<0>(val);
        int item_index = get<2>(val);

        if(last_genre != current_genre) {
            // 새 장르 시작
            last_genre = current_genre;
            cnt = 1;
            answer.push_back(item_index);
        } else if(cnt < 2) {
            // 같은 장르의 아이템 추가 (최대 2개까지)
            cnt++;
            answer.push_back(item_index);
        }
        // 만약 같은 장르에서 더 이상 추가할 아이템이 없으면 자동으로 다음 장르로 넘어갑니다.
    }
    
    return answer;
}