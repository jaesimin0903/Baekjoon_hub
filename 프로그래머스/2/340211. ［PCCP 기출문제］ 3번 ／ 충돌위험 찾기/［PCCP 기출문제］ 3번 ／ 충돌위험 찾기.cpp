#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <map>

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

map<int, int> m[110][110];

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    set<pair<int,int>> s;
    for(auto v: routes){
        int num =0;
        for(int i =0;i<v.size()-1;i++){
            int sy = points[v[i]-1][0];
            int sx = points[v[i]-1][1];
            int ey = points[v[i+1]-1][0];
            int ex = points[v[i+1]-1][1];
            
            int y_gap = ey - sy;
            int x_gap = ex - sx;
            
            if(i==0)m[sy][sx][num]++;
            
            while(sy != ey){
                if(y_gap <0 ){
                    sy-=1;
                }else if(y_gap > 0){
                    sy+=1;
                }
                ++num;
                //cout << sy << " " << sx << " "<< num << "\n";
                m[sy][sx][num]++;
            }
            
            while(sx != ex){
                if(x_gap <0 ){
                    sx-=1;
                }else if(x_gap > 0){
                    sx+=1;
                }
                ++num;
                //cout << sy << " " << sx << " "<< num << "\n";
                m[sy][sx][num]++;
            }
        }
        //break;
    }
    
    for(int i =0;i<110;i++){
        for(int j =0;j<110;j++){
            //cout << m[i][j].size();
            for(auto val = m[i][j].begin(); val != m[i][j].end();val++){
                
                if(val->second > 1) {
                    //cout <<"i " << i << " j " << j << " "<< val->first<< " " << val->second <<"\n";
                    answer++;}
            }
        }
        //cout << "\n";
    }
    
    return answer;
}