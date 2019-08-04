#include <iostream>
using namespace std;
int mat[100][20];
int m;
int n;


// function to toggle cols
void toggle(int c){
    for(int i = 0; i < m; i++){
        if(mat[i][c] ==1){
            mat[i][c] = 0;
        }
        else{
            mat[i][c] = 1;
        }
    }
}

//an exhausting function which checks the maxrows by considering all the moves

void go(int col, int k , int& ans) {
    if (k %2 == 0){
        
        int nRow = 0;
        for(int i = 0; i < m; i ++){
            int count = 0;
            for (int j = 0 ; j < n; j++){
                count ++ ;
            }
            if (count == n){
                nRow++;
            }
        }

        if (nRow > ans){
            ans = nRow;
        }
    }

 
    if (col >= n || k == 0){
        return;
    }

    toggle(col); // toggle the first col
    go(col + 1, k-1, ans);// then check
    toggle(col);// restoring the original value of the first column
    go(col + 1, k, ans);

}

int main(){
    int t;
    cin>>t;
    while (t--){
        int k;
        cin>>m>>n>>k;
        for (int i = 0; i < m ; i++){
            for (int j = 0; j<m; j++){
                cin>>mat[i][j];
            }
}
        int as = 0;
        go(0, k, as);
        cout<< as;
    

}

    return 0;
}
