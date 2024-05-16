
#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

    cin >> T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str;
        cin >> str;
        cout << "#" << test_case << " ";
        int s = 0;
        int e = str.size()-1;
        bool is_ans = true;
        while(s < e){
            if(str[s] != str[e]){
                is_ans = false;
                break;
            }
            s++;
            e--;
        }
        
        int part = (str.size()-1)/2;
        s = 0;
        e = part-1;
		while(s < e){
            if(str[s] != str[e]){
                is_ans = false;
                break;
            }
            s++;
            e--;
        }
        
        e = str.size()-1;
        s = str.size() -1 - part + 1;
        
        while(s < e){
            if(str[s] != str[e]){
               	is_ans = false;
                break;
            }
            s++;
            e--;
        }
        if(is_ans) cout << "YES" << "\n";
        else cout << "NO\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}