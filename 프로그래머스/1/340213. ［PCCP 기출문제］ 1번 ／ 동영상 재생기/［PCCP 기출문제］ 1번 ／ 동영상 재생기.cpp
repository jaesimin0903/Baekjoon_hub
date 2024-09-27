#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "00:00";
     
    int end_hour = stoi(string(1, video_len[0]) + string(1, video_len[1]));
    int end_min = stoi(string(1, video_len[3]) + string(1, video_len[4]));
    
    int cur_hour = stoi(string(1, pos[0]) + string(1, pos[1]));
    int cur_min = stoi(string(1, pos[3]) + string(1, pos[4]));
    
    int op_start_hour = stoi(string(1, op_start[0]) + string(1, op_start[1]));
    int op_start_min = stoi(string(1, op_start[3]) + string(1, op_start[4]));
    
    int op_end_hour = stoi(string(1, op_end[0]) + string(1, op_end[1]));
    int op_end_min = stoi(string(1, op_end[3]) + string(1, op_end[4]));
    
 if(cur_hour == end_hour && cur_min > end_min){
            cur_min = end_min;
            cur_hour = end_hour;
            cur_min = end_min;
        }
        if(op_start_hour < op_end_hour){
            if(op_start_hour == cur_hour && op_start_min <= cur_min){
                cur_hour = op_end_hour;
                    cur_min = op_end_min;
            }else if(op_end_hour == cur_hour && op_end_min >= cur_min){
                cur_hour = op_end_hour;
                    cur_min = op_end_min;
            }else if(op_start_hour < cur_hour && cur_hour < op_end_hour){    
                 cur_hour = op_end_hour;
                    cur_min = op_end_min;
            }
        }
            else if(op_start_hour == op_end_hour&& op_start_hour == cur_hour){
            if(op_start_min <= cur_min && cur_min <= op_end_min){
                cur_hour = op_end_hour;
                cur_min = op_end_min;
            }
        }
    
    for(string cmd : commands){
        
        
        if(cmd == "next"){
            cur_min += 10;
            if(cur_min >= 60){
                cur_min -= 60;
                cur_hour++;
            }
            
        }else if(cmd == "prev"){
            cur_min -= 10;
            if(cur_min < 0){
                cur_min += 60;
                cur_hour--;
            }
        }
        
        if(cur_hour < 0){
            cur_hour = 0;
            cur_min = 0;
        }
        
        if(cur_hour == end_hour && cur_min > end_min){
            cur_min = end_min;
        }else if(cur_hour > end_hour){
            cur_hour = end_hour;
            cur_min = end_min;
        }
        
        if(op_start_hour < op_end_hour){
            if(op_start_hour == cur_hour && op_start_min <= cur_min){
                cur_hour = op_end_hour;
                    cur_min = op_end_min;
            }else if(op_end_hour == cur_hour && op_end_min >= cur_min){
                cur_hour = op_end_hour;
                    cur_min = op_end_min;
            }else if(op_start_hour < cur_hour && cur_hour < op_end_hour){    
                 cur_hour = op_end_hour;
                    cur_min = op_end_min;
            }
        }
        else if(op_start_hour == op_end_hour && op_start_hour == cur_hour){
            //cout << "2 " << op_start_hour << " " << cur_hour << "\n";
            if(op_start_min <= cur_min && cur_min <= op_end_min){
                cur_hour = op_end_hour;
                cur_min = op_end_min;
            }
        }
        
        //cout << cur_hour << " " << cur_min << "\n";
    }
    
    answer[0] = '0' + (cur_hour / 10);
    answer[1] = '0' + (cur_hour % 10);
    answer[3] = '0' + (cur_min / 10);
    answer[4] = '0' + (cur_min % 10);
    
    return answer;
}
