

#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
        int num[10];
        int cnt = 0;
        cin >> n;
        int d = n;
        for(int i =0;i<10;i++){
            num[i] = -1;
        }
        while(1){
        	string str = to_string(d);
           
            for(int i = 0;i<str.size();i++){
                
                num[str[i] - '0'] = 1;
            }
            
            bool is_ok = true;
            for(int i = 0;i<10;i++){
                if(num[i] == -1) is_ok = false;
            }
            
            if(is_ok){
                //cout << 1;
                break;
            }
            else cnt ++;
            d +=n;
        }
        cout << "#" << test_case << " " << d<< "\n";
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}