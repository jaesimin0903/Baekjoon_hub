#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

long long N, M;
int choose[10];

class Node{
    public:
        char value;
        char left;
        char right;

    Node() : value(' '),left(' '),right(' '){}
    //Node(int val):value(val),left(nullptr), right(nullptr){}
};

class BinaryTree{
    private:
        Node * root;

    public:
        BinaryTree() : root(nullptr){}
        ~BinaryTree();

        void insert(Node *&node,int value[3]);
};



int num[1001];
    bool visited[27];

void preorder(Node *nodes, int idx) {

    if (nodes[idx].value == ' ' || nodes[idx].value == '.') { // 현재 노드가 없으면 반환
        return;
    }

    cout << nodes[idx].value; // 현재 노드 방문 (출력)

    int l = nodes[idx].left - 'A'; // 왼쪽 자식
    int r = nodes[idx].right - 'A'; // 오른쪽 자식

    if (l >= 0 && l < 26) { // 유효한 왼쪽 자식이 있으면 방문
        preorder(nodes, l);
    }
    if (r >= 0 && r < 26) { // 유효한 오른쪽 자식이 있으면 방문
        preorder(nodes, r);
    }
}

void inorder(Node *nodes, int idx) {
    if (nodes[idx].value == ' ' || nodes[idx].value == '.') {
        return;
    }

    int l = nodes[idx].left - 'A'; // 왼쪽 자식
    int r = nodes[idx].right - 'A'; // 오른쪽 자식

    if (l >= 0 && l < 26) {
        inorder(nodes, l);
    }

    cout << nodes[idx].value; // 현재 노드 방문 (출력)

    if (r >= 0 && r < 26) {
        inorder(nodes, r);
    }
}

void postorder(Node *nodes, int idx) {
    if (nodes[idx].value == ' ' || nodes[idx].value == '.') {
        return;
    }

    int l = nodes[idx].left - 'A'; // 왼쪽 자식
    int r = nodes[idx].right - 'A'; // 오른쪽 자식

    if (l >= 0 && l < 26) {
        postorder(nodes, l);
    }

    if (r >= 0 && r < 26) {
        postorder(nodes, r);
    }

    cout << nodes[idx].value; // 현재 노드 방문 (출력)
}



int main (){
    int T;
    cin >> N;
    
    Node *nodes = new Node[N+1];

    for(int i = 0;i<N;i++){
        char c, l, r;
        cin >> c >> l >> r;
        nodes[c-'A'].value = c;
        if(l != '.')
            nodes[c-'A'].left = l;
        if(r!='.')
            nodes[c-'A'].right = r;

    }

    preorder(nodes,0);
    cout << "\n";
    inorder(nodes,0);
    cout << "\n";
    postorder(nodes,0);

    return 0;
}