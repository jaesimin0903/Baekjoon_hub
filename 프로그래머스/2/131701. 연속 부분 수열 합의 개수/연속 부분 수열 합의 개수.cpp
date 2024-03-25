#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

unordered_set<int> us;

int solution(vector<int> elements) {
    int answer = 0;
    
    int window =1;
    //슬라이딩 윈도우 (1~원소의 최대개수)
    
    while(window<=elements.size()){
        int left=0,right=window-1;
        int sum =0;
        
        for(int i = left;i<elements.size();i++){
            for(int j = i;j<i+window;j++){
                if(j >= elements.size()){
                    sum+=elements[j-elements.size()];
                }else{
                    sum+=elements[j];
                }
            }
            //cout << sum << " " << window << "\n";
            us.insert(sum);
            sum = 0;
        }
        window++;
    }
    answer = us.size();
    for(auto v: us){
        //cout << v << " ";
    }
    return answer;
}