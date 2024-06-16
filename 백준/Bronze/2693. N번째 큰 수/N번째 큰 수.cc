#include <iostream>
#include <vector>
#include <deque>
#include<unordered_set>
#include<algorithm>
#include<string>
#include <cmath>
using namespace std;

typedef long long ll;


int main() {
    
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        int A[10];
        for(int j =0;j<10;j++){
            cin >> A[j];
        }
        sort(A,A+10);
        cout << A[7] << '\n';
    }


    return 0;
}
