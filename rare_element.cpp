/*
below is a sample input for the code

1
8 3
2 2
2 8
7 8
1 1 0 0 0 0 0 0 
1 1 0 0 1 1 1 1
1 1 0 0 1 0 0 0
1 1 1 1 1 0 0 0 
0 1 0 0 1 0 0 0
0 1 0 0 1 0 0 0
0 1 0 0 1 1 1 1
0 1 0 0 0 0 0 0

 */


#include <iostream>
using namespace std;
int mat[20][20];
int visited[4][20][20];
int C;
int N;
int rare[4][2];

struct node{
    int x; 
    int y;
    node(int a, int b){
        x = a;
        y = b;
    }
    node(){}

};

struct ll{
    node data;
    ll* next;
    ll(node d){
        data = d;
        next = NULL;
    }
    ll(){
        next = NULL;
    }
};

class queue{
    ll* front;
    ll* back;
    int size;
    public:
    queue(){
        size  = 0;
        front = NULL;
        back = NULL;
    }
    bool isEmpty();
    void push(int a, int b);
    node pop();
    
};

bool queue::isEmpty(){
    if (size == 0){
        return true;
    }
    return false;
}

void queue::push(int a, int b){
    if (isEmpty()){
        node d;
        d.x = a;
        d.y = b;
        ll * temp;
        temp = new ll(d);
        front = temp;
        back = temp;
    }
    else{
        node d;
        d.x = a;
        d.y = b;
        ll * temp;
        temp = new ll(d);
        back -> next = temp;
        back = back -> next;
    }
    size ++;
}
node queue:: pop(){
    node d;
    d = front ->data;
    ll*temp = front -> next;
    free(front);
    front = temp;
    size --;
    return d;
}

bool safe(int x, int y){
    if (mat[x][y] != 1 || x>= N|| x<0 || y >= N || y < 0){
        return false;

    }
    return true;
}

void go(int n, int x, int y){
    queue q;
    q.push(x, y);
    visited[n][x][y] = 0;
    while (!q.isEmpty()){
        node d = q.pop();
        x = d.x;
        y = d.y;
        if (safe(x+1, y) && visited[n][x+1][y] == -1){
            visited[n][x+1][y] = visited[n][x][y] + 1;
            q.push(x+1, y);
        }
        if (safe(x-1, y) && visited[n][x-1][y] == -1){
            visited[n][x-1][y] = visited[n][x][y] + 1;
            q.push(x-1, y);
        }
        if (safe(x, y+1) && visited[n][x][y+1] == -1){
            visited[n][x][y+1] = visited[n][x][y] + 1;
            q.push(x, y+1);
        }
        if (safe(x, y-1) && visited[n][x][y-1] == -1){
            visited[n][x][y-1] = visited[n][x][y] + 1;
            q.push(x, y-1);
        }
    }

}




void solve(){
    for (int i = 0; i < C; i++){
        go (i, rare[i][0], rare[i][1]);
    }

    int overall = 1e7;
    int bigshort = -1; 
    for (int i = 0 ; i <N; i++){
        for (int j = 0; j < N; j++){

            for (int k = 0, sum = 0, maxi = 0  ; k < C; k++){
                if (visited[k][i][j] == -1){
                    break;
                }
                sum += visited[k][i][j];
                maxi = max(maxi, visited[k][i][j]);
                if(k == C-1){
                    if (sum < overall){
                        overall = sum;
                        bigshort = maxi;
                    }
                }
            }
            
        }

    }

    cout << bigshort;
}





int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N>>C;
        for (int i = 0; i < C; i++){
            cin>>rare[i][0]>>rare[i][1];
            rare[i][0]--;
            rare[i][1]--;
        }
        for (int i = 0 ; i < N ; i ++){
            for(int j = 0; j < N; j++){
                cin>>mat[i][j];
                for (int k = 0; k < C ; k++){
                visited[k][i][j] = -1;
                }
            }
        }
        solve();
    }

}


