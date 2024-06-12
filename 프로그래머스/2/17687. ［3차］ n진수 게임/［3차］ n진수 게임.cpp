#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string ans_arr = "";
    string part ="";
    for(int i = 0;i<100000;i++){
        int num = i;
        int div = n;

        while(1){
            int val = num % n;
            if(val == 10){
                part = 'A' + part;
            }else if(val == 11){
                part = 'B' + part;
            }else if(val == 12){
                part = 'C' + part;
            }else if(val == 13){
                part = 'D' + part;
            }else if(val == 14){
                part = 'E' + part;
            }else if(val == 15){
                part = 'F' + part;
            }else{
            part = to_string(num % n) + part ;
                
            }
            //else part += "0";
            
            num /= n; 
            //100 % 16 = 4
            //84  
            if(num == 0)break;
        }
        ans_arr += part;
        //cout << i << " "<< part << "\n";
        part = "";
    }
    
    for(int i = p-1;i<m*t;i+=m){
        answer+=ans_arr[i];
    }
    
    return answer;
}

//0 10 100 110 1000 
//1 11 101 111