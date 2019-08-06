#include <iostream>
using namespace std;
int N;
int det[5][5];
int dp[13][5];
int mat[13][5];
int d;
int max(int a, int b){
    if (a>b){
        return a;
    }
    return b;
}
int max(int a, int b, int c){
    if (a>b){
        if (c>a){
            return c;
        }
        return a;
    }
    else{
        if (c>b){
            return c;
        }
        return b;
    }
}

bool explode(int i){
    int count = 0;
    for (int j = 0; j < 5; j++){
        if (mat[i][j]<0){
            count ++;
        }
    }
    return (count == 5);
    
}

void detonate(int r){
    for (int i = r; i > r- 5 && r>=0; i --){
        for (int j = 0; j < 5; j++){
            det[r - i][j] = 0;
            if (mat[i][j] == -1){
                det[r-i][j] = -1;
                mat[i][j] = 0;
            }
        }
    }
}
void undet(int r){
    for (int i = r; i > r- 5 && r>=0; i --){
        for (int j = 0; j < 5; j++){
           if (det[r- i][j] == -1){
                mat[i][j] = -1;            
                }
        }
    }
}
void go(){
    
    dp[N-1][0] = dp[N-1][4] = -7;
    for(int i = N-2; i >=0 ; i--){
        for(int j =0; j < 5; j++){
            if (j == 0){ //keep track that it is i + 1 and not i-1 because we are moving brom the last of a matrix to the start of the matrix
                dp[i][j] = max(mat[i][j] + dp[i+1][j], dp[i+1][j+1] + mat[i][j]);
            }
            else if(j == 4){
                dp[i][j] = max(mat[i][j] + dp[i+1][j], dp[i+1][j-1] + mat[i][j]);
            }
            else{
                dp[i][j] = max(mat[i][j]+ dp[i+1][j], mat[i][j] + dp[i+1][j-1], dp[i+1][j+1] + mat[i][j]);
            }
        }
        if (explode(i)){
            break;
        }
    }
    int maxi = dp[0][1];
    for (int i = 1; i < 5; i++){
        if(dp[0][i] > maxi){
            maxi = dp[0][i];
        }

    }
    /*
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 5; j ++){
            cout<< dp[i][j]<<"  ";
            
        }
        */
        cout<< maxi;

}








void solve(){
    for (d = N; d >0; d--){
        detonate(d-1);
        go();
        undet(d -1);
    }
    
}


int main(){
    int t; 
    cin>>t;
    while (t--){
    cin>>N;
    for (int i = 0 ; i <N; i++){
        for(int j = 0; j < 5; j++){
            cin>>mat[i][j];
            if (mat[i][j] ==2){
                mat[i][j] =-1;
            }
            if (i == N-1 && j>0 && j < 5){
                dp[i][j] = mat [i][j];
            }
            else{
            dp[i][j] =0;
            }
            
        }
    }
    solve();
    cout<< endl;
    }
    return 0;

}
    

