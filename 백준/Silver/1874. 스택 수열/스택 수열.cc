#include<iostream>
#include<stack>
#include<queue>
using namespace std;
queue<bool>q;
stack<int> s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int n,val,max=1; //max는 현재 최고값
    s.push(0); //스택에 0을 넣고 시작함
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        if(s.top()<val){ //스택의 top이 입력된값보다 작으면
            for(int i=max;i<=val;i++){ //max값부터 입력값까지 스택에 쌓아줌
                s.push(i);
                q.push(1);                //큐에는 true를 push
            }
            max=val+1; //max는 입력값 다음값을 넣어줌
        }
        if(s.top()==val){     //스택에 값이 다 쌓였으면 입력된값에 대해 -를 해줘야하기에 
            s.pop();        //top값이 val과 같으면 pop을 해줌
            q.push(0);        //큐에는 false push
        }
        if(s.top()>val){    //top값이 val보다 크면 수열을 만들수 없으므로 NO출력후 그냥 나가버림
            cout<<"NO";
            exit(0);
        }
    }
    while(!q.empty()){ //큐에 push된 bool값들을 각자 + - 로 변환하여 출력 
        cout<<(q.front()?'+':'-')<<"\n";
        q.pop();
    }
}
