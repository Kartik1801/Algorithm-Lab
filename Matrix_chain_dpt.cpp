#include <iostream>
using namespace std;
void print(int s[][4],int i,int j){
    if(i==j){
        cout<<" A"<<i<<" ";
    } else {
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}
void mco(int d[],int n,int c[][5],int s[][4]){
    int q;
    n=n-1;
    int i, j, k,l;
    for (int l = 2 ; l <= n ; l++ ){
        for ( int i = 0 ; i <= n - l + 1 ; i++ ){
            int j = l +  i - 1;
            c[i][j] = INT16_MAX;
            for ( int k = i; k <= j - 1 ; k++ ){
                q= c[i][k] + c[k+1][j] + d[i-1]*d[k]*d[j];
                if( q < c[i][j] ){
                    c[i][j] = q;
                    s[i][j] = k;
                }
            }
        } 
    }
}
int main(){
    int m[] = { 3, 2, 4, 2, 5 };
    int n = sizeof(m) / sizeof(m[0]);
    int c[5][5], s[4][4];
    for ( int i = 0; i < n; i++){
        c[i][i] = 0;
    }
    mco(m, n, c, s);
    cout << c[1][4] << endl << print(s,1,4);
    return 0;
}