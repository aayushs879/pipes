#include <iostream>
using namespace std;
int mat[50][50];
bool visited[50][50];
int L;
int m, n;
int x, y;

struct node{
	int x;
	int y;
	int l;
	node(int a, int b, int c){
	    x = a;
	    y = b;
	    l = c;
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
};

class queue{
	int size;
	ll * front;
	ll * back;
public:
    queue(){
        front = NULL;
        back = NULL;
        size = 0;
        
    }
	void push(int a, int b, int c);
	node pop();
	bool isEmpty();
	node top();
};

bool queue::isEmpty(){
	if (size == 0){
		return true;
	}
	return false;
}


void queue::push(int a, int b, int c){
	if (isEmpty()){
		node d;
		d.x = a;
		d.y = b;
		d.l = c;
		ll* temp = new ll(d);
		front = temp;
		back = temp;
	}
	else{
		node d;
		d.x = a;
		d.y = b;
		d.l = c;
		ll* temp = new ll(d);
		back -> next = temp;
		back = temp;
	}
	size++;
}

node queue::pop(){
	node d = front ->data;
	ll * temp = front-> next;
	free(front);
	front = temp;
	size--;
	return d;
	
}

bool safe(int i, int j, string dir){
	if (dir == "up"){
		if (i-1<0){
			return false;
		}
	}
	if (dir == "down"){
		if (i +1>=m){
			return false;
		}
	}
	if (dir == "right"){
		if (j + 1 >= n){
			return false;
		}
	}
	if (dir == "left"){
		if (j -1 < 0){
			return false;
		}
	}
	return true;
}


bool is_connected(int i, int j, string dir){
	if (!safe(i, j, dir)){
		return false;
	}
	if (dir == "up"){
		if (mat[i][j] == 1 || mat[i][j] == 2 || mat[i][j] == 4 || mat[i][j] == 7){
			if (mat[i-1][j] == 1 || mat[i-1][j]== 2 || mat[i-1][j] == 5 || mat[i-1][j] == 6){
				return true;
			}
		}
	}
	else if (dir == "down"){
		if (mat[i][j] == 1 || mat[i][j] == 2 || mat[i][j] == 5 || mat[i][j] == 6){
			if (mat[i+1][j] == 1 || mat[i+1][j] == 2 || mat[i+1][j] == 4 || mat[i+1][j] == 7){
				return true;
			}
		}
	}
	else if(dir == "right"){
		if (mat[i][j] == 1 || mat[i][j] == 3 || mat[i][j] == 4 || mat[i][j] == 5){
			if (mat[i][j+1] == 1 || mat[i][j+1] == 3 || mat[i][j+1] == 6 || mat[i][j+1] == 7){
				return true;
			}
		}
	}
	else if (dir == "left"){
		if (mat[i][j] == 1 || mat[i][j] == 3 || mat[i][j] == 6 || mat[i][j] ==7){
			if (mat[i][j-1] == 1 || mat[i][j-1] == 3 || mat[i][j-1] == 4 || mat[i][j-1] == 5){
				return true;
			}
		}
	}
	return false;
}

void solve(){

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin>>mat[i][j];
			visited[i][j] = false;
		
		}
		
	}


	queue q;
	
	int count = 0;
	q.push(x, y, L-1);
	visited[x][y] = true;
	while (!q.isEmpty()){
		node d = q.pop();
		x = d.x;
		y = d.y;
		int l = d.l;
		if (mat[x][y] == 0){
		    break;
		}
		
		count+= 1;
		if (l>0){
		    
    		if(is_connected(x, y, "up")&& !visited[x-1][y]){
    			q.push(x-1, y, l-1);
    			visited[x-1][y] = true;
    		
    		}
    		if(is_connected(x, y, "down")&& !visited[x+1][y]){
    			q.push(x+1, y, l-1);
    		    visited[x+1][y] = true;
    		}
    		if(is_connected(x, y, "right")&& !visited[x][y+1]){
    			q.push(x, y+1, l-1);
    			visited[x][y+1] = true;
    		
    		}
    		if(is_connected(x, y, "left")&& !visited[x][y-1]){
    			q.push(x, y-1, l-1);
    		    visited[x][y-1] = true;
    		}
		}

	}

	cout<< count<<endl;

}



int main(){
	int t;
	cin>>t;
	while (t--){
		cin>>m>>n>>x>>y>>L;
		solve();
	}



	return 0;
}
