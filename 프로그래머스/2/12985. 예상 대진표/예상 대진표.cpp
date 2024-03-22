#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    if(a>b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    while(a!=b){
        if(a%2 == 1){
            a = a/2+1;
        }else{
            a /=2;
        }
        if(b%2 == 1){
            b = b/2+1;
        }else{
            b/=2;
        }
        answer++;
    }

    return answer;
}