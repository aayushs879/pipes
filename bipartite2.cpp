#include <iostream>
using namespace std;
int mat[4][4] = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    };
int V = 4;

struct node{
    int data;
    node * next;
    node (int a){
        data = a;
        next = NULL;

    }
};

class queue{
    int size;
    node* front;
    node* back;
    public:
    queue(){
        size = 0;
        front = NULL;
        back = NULL;

    }
    bool isEmpty();
    void push(int a);
    int pop();

};

bool queue::isEmpty(){
    if (size == 0) return true;
    return false;
}
void queue::push(int a){
    if(isEmpty()){
        node * temp;
        temp = new node(a);
        front = temp;
        back = temp;
    }
    else{
        node * temp;
        temp = new node(a);
        back -> next = temp;
        back = temp;
    }
    size++;

}

int queue::pop(){
    int a = front -> data;
    front = front -> next;
    size--;
    return a;
}

bool isBipartite(int s, int c, int color[]){
    queue q;
    q.push(s);
    color[s] = c;
    while (!q.isEmpty()){
        s = q.pop();
        c = color[s];
        if (mat[s][s] == 1) return false;
        for (int i = 0 ; i < V; i++){
             if (mat[s][i] == 1 && color[i] == -1){
                 color[i] = 1-c;
            } 
            if (color[i] == c && mat[s][i] == 1){
                return false;
            }
        }

    }
    return true;

}
int main(){
    int color[V];
    for (int i = 0; i < V; i++){
        color[i] = -1;
    }
    if (isBipartite(0, 1, color)){
        cout<< "YES";
    }
    else{
        cout<<"NO";
    }



    return 0;
}