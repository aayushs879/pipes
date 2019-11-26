#include <iostream>
using namespace std;
int mat[50][50]; // the global variable for the matrix to store the inputs
bool visited[50][50]; // a boolean array to store if the pipe is visited or not
int L;
int m, n;
int x, y;


// a node structure which stores the co-ordinates of a pipe and the corresponding length of the tool used up to reach there
struct node{
	int x;
	int y;
	int l;
	node(int a, int b, int c){ //node constructor
	    x = a;
	    y = b;
	    l = c;
	}
	node(){}// default constructor

};


//a structure to make a linked list of the node structure that we have created so we can create a queue out of it later
struct ll{
	node data;
	ll* next;
	ll(node d){
	    data = d;
		next = NULL;
	}
};


//linked list implementation of the queue
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
	size++; //keep track of this shit
}

node queue::pop(){
	node d = front ->data;
	ll * temp = front-> next;
	free(front); // memory efficiency, can also avoid this step
	front = temp;
	size--;//same when popping an element
	return d;
	
}

// a function to check if the traversal is safe or not
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


// a function to check if the neighbor is connected or not

bool is_connected(int i, int j, string dir){
	if (!safe(i, j, dir)){
		return false;
	}
    //consider the question for these connections
	if (dir == "up"){
		if (mat[i][j] == 1 || mat[i][j] == 2 || mat[i][j] == 4){
			if (mat[i-1][j] == 1 || mat[i-1][j]== 2 || mat[i-1][j] == 5 || mat[i-1][j] == 6){
				return true;
			}
		}
	}
	else if (dir == "down"){
		if (mat[i][j] == 1 || mat[i][j] == 2 mat[i][j] == 6){
			if (mat[i+1][j] == 1 || mat[i+1][j] == 2 ||  mat[i+1][j] ==3){
				return true;
			}
		}
	}
	else if(dir == "right"){
		if (mat[i][j] == 1 || mat[i][j] == 3 || mat[i][j] == 4 || mat[i][j] == 5){
			if (mat[i][j+1] == 1 || mat[i][j+1] == 3 || mat[i][j+1] == 7){
				return true;
			}
		}
	}
	else if (dir == "left"){
		if (mat[i][j] == 1 || mat[i][j] == 3 || ){
			if (mat[i][j-1] == 1 || mat[i][j+1] == 4 || mat[i][j+1] == 5){
				return true;
			}
		}
	}
	return false;
}

void solve(){
// taking inputs for the matrix and correspondingly marking the bool array as false
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin>>mat[i][j];
			visited[i][j] = true;
		
		}
		
	}


	queue q;
	//making a queue of nodes structure
	int count = 0; // to check how many pipes can be visited
	q.push(x, y, L-1); //  L-1 as one unit of lenth is required by the orginal position of the pipe only and we are appending the original starting element of the pipe here
	visited[x][y] = true; //marking the first element as visited
    // made a mistake of marking this true inside the loop, ended up fucking the whole problem completely
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
    			visited[x-1][y] = true; // this step is important here, if we dont do this a particular element might be a neighbor of many pipes and it gets appended to the queue many times 
                // resulting in multiple iterations and thus fucking up your count value totally
    		
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
