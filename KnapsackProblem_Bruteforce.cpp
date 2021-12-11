// Brute Force knapsack problem : Complexity => O(2^n)
#include <iostream>
using namespace std;
class item{
public:
    int weight;
    int value;
};
int BB(int a,int b){
int t=a>>b;
t=t&1;
return t;
}
void BruteForceKnapsack(item I[],int n,int W){
    int maxw=0,maxv=0,subset=0;
    for ( int i = 0; i < 1 << n; i++ ){
        int value = 0, weight = 0;
        for ( int j = 0 ; j < n; j++){
            if (BB(i,j)){
                weight += I[j].weight;
                value += I[j].value;
            }
        }
        if(value>=maxv&&weight<=W){
            maxv=value;
            maxw=weight;
        }
    }
    cout<<maxv<<endl<<maxw;

}
int  main(){
    item I[3];
    I[0].weight=5,I[0].value=6;
    I[1].weight=4,I[1].value=5;
    I[2].weight=3,I[2].value=4;
    int W=7;
    BruteForceKnapsack(I,3,W);
    return 0;
}