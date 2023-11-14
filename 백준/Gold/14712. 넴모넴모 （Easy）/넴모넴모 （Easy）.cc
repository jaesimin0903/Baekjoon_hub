#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#include<cmath>
using namespace std;

vector<int> res;
int w = 0;
int b = 0;

void print(vector<vector<int>>v) {
    for (auto& row : v) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }
}


long long int ans = 0;

int row, col;

vector<vector<int>> v;

void dfs(int i, int j) {


    if (i == row - 1 && j == col) {
        ans++;
        return;
    }
    

    if (j >= col) {
        i++;
        j = 0;
    }

    
    v[i][j] = 1;

    if (i - 1 >= 0 && j -1 >=0) {
        
        if (v[i - 1][j - 1] && v[i - 1][j] && v[i][j - 1]) {
           
            v[i][j] = 0;


            //dfs(i, j + 1);
        }
        else {
            v[i][j] = 1;

            //print(v);
            dfs(i, j + 1);
        }
    }
    else {
        v[i][j] = 1;
        //print(v);
        dfs(i, j + 1);
    }
    
    v[i][j] = 0;
    //print(v);
    dfs(i, j + 1);
}



int main() {

    cin >> row >> col;

    v = vector<vector<int>>(row, vector<int>(col, 0));

    dfs(0, 0);
    cout << ans;
    return 0;
}

