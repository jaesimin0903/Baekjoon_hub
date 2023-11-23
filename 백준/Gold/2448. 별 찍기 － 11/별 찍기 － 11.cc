#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int N;


char ans[3072][6144];
void printS(int x, int y){
    // cout << "  *  " << "\n";
    // cout << " * * "<< "\n";
    // cout << "*****"<<"\n";

    ans[y][x] = '*';
    ans[y+1][x-1] = '*';
    ans[y+1][x+1] = '*';

    for(int i = 0;i<5;i++){
        ans[y+2][x-2+i] = '*';
    }
}
void dc(int x,int y,int size){
    if(size ==3){
        printS(x,y);
        return;
    }

    dc(x,y,size/2);
    dc(x-size/2, y+size/2, size/2);
    dc(x+size/2,y+size/2,size/2);

}





int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;


    for(int i = 0;i<N;i++){
        for(int j = 0;j<N*2-1;j++){
            ans[i][j] = ' ';
        }
    }


    dc(N-1,0,N);


    for(int i = 0;i<N;i++){
        for(int j =0;j<N*2-1;j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
    return 0;
}