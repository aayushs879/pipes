#include <iostream>
using namespace std;
int mat[12][5]; //declare as a global variable
int n; //no. of rows
int det[5][5]; // we're gonna detonate each and every row and undetonate it to check all the cases

//this function stores the detonated bomnbs' location in a mirror order manner
void detonate(int r){
    for (int i = r; i > r-5 && i >=0; i--)
        for (int j =0; j < 5; j++){
            det[r-i][j] = 0; // this shit helps in initializing the array of det to 0s
            if (mat[i][j] == 2){
                mat[i][j] = 0;
                det[r-i][j] = 0;
            }
        }
}

//the undetonate function
void undet(int r){
    for (int i = r; i >r-5 && i >= 0; i--)
        for (int j = 0; j <5 ; j++){
            if (det[r-i][j] == 2 ){
                mat[i][j] = 2;
            }
        }
}


//exhaust all moves to see what works
void go (int n, int pos, int c, int & ans){ //pass the ans shit by reference so c++ doesnt create a copy of that during each recursive step
    if (pos < 0 || pos >4 || c ==-1){ // c= -1 condition is important as we're not gonna go ahead if the coins become -1 at any instant of time
        return;
    }

    //the shit below is simple enough
    if (mat[n -1][pos] == 1){
        c +=1;
    }
    else if (mat[n-1][pos] == 2){
        c -=1;
    }
    //if we have gone through the last row
    if (n == 1){
        if (c >ans){
            ans = c;
        }
    }

    //checking for all the moves; recursion is a bitch
    else{
        go(n -1, pos , c, ans);
        go(n -1, pos +1 , c, ans);
        go(n -1, pos -1, c, ans);
    }
}

int main(){
    int t;
    cin>> t;
    int count =1 ;
    whlle(t--){
        int max=-1;
        for (int i = 0; i < n; i++){
            int c = -1;
            detonate(i);
            go(n, 2, 0, c);
            if (c> max){
                max = c;
            }
            undet(i);

            if (max< 0){
                max = -1;
            }
            cout<<"#"<<count<<" "<<max;
    }
    }






    return 0;
}
