#include <iostream>
using namespace std;
int mat[12][5];
int n; //no. of rows
int det[5][5];


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

void undet(int r){
    for (int i = r; i >r-5 && i >= 0; i--)
        for (int j = 0; j <5 ; j++){
            if (det[r-i][j] == 2 ){
                mat[i][j] = 2;
            }
        }
}

void go (int n, int pos, int c, int & ans){
    if (pos < 0 || pos >4 || c ==-1){
        return;
    }
    if (mat[n -1][pos] == 1){
        c +=1;
    }
    else if (mat[n-1][pos] == 2){
        c -=1;
    }

    if (n == 1){
        if (c >ans){
            ans = c;
        }
    }
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