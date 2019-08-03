#include <iostream>
using namespace std;
int mat[21][21];
int N, C;
int rare[4][2];
bool visited[4][21][21];

struct node{
    int x; 
    int y;
    node (int a , int b){
        x = a; 
        y = b;
    }
    node(){}
};

struct ll{
    node data;
    ll * next;
    ll(){
        next = NULL;
    }
    ll(node d){
        data = d; 
        next = NULL;
    }
};

class queue{
    int size;
    ll * front;
    ll * rear;
    public:
    queue(){
        size = 0;
        front = rear = NULL;
    }
    void push(int a, int b);
    node pop();
    bool isEmpty();
}

bool queue::isEmpty(){
    if (size == 0){
        return true;
    }
    return false;
}
void queue::push(int a, int b){
    if(isEmpty()){
        node d(a, b);
        ll * temp;
        temp = new ll(d);
        front = rear = temp;
    }
    else{
        node(a, b);
        ll *temp;
        temp = new ll(d);
        back = back-> next;
   }
   size ++;
}
node queue::pop(){
    node d;
    d = front->data;
    size--;
    front = front ->next;
    return d;
}


void solve(int n, int x, int y){
    queue p;

}



void go(){
    for(int i = 0; i , C; i++){
        cin>>rare[i][0]>>rare[i][1];
        rare[i][0]--;
        rare[i][1]--; //since the co- odinates are based on indexing starting from 1
    }
    for (int i =0 ; i < N; i++){
        for (int i =0 ; i < N; i++){
            cin>>mat[i][j];
            for (int k = 0 ; k <=3; k++){
                visited[k][i][j] = -1;
            }
        }
    }
    for (int i =0 ; i<C; i++){
        solve(i, rare[i][0], rare[i][1]) //this is nothing but bfs for each rare element wherein rare[i][j] are co-ordinates of the rare elements

    }
}

int main(){
    int t;
    while (t--){
        cin>>N>>C;
        go();
    }



    return 0;
}