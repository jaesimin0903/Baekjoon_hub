#include <iostream>
#include <string>
#include <vector>
//abcdefghijklmnopqrstuvwsyz 26
// a-z 25 24
// z-a 1 2
using namespace std;



int solution(string name) {
    int answer = 0;
    
    int l1 = 0;
    int l2 = 0;
    int i = 0;
    int move = name.length()-1;
    for(int i = 0;i<name.length();i++){
        answer += min(name[i]-'A', 'Z'-name[i]+1);
        
        l1 = i;
        int l2_idx = l1+1;
        
        while(l2_idx < name.length()){
            if(name[l2_idx] != 'A')
                break;
            else l2_idx++;
        }
        
        l2 = name.length() -1 - l2_idx +1;
        
       move =  min(move, l1+l2+min(l1,l2));
        
        
    }
    
    
    return answer+move;
}