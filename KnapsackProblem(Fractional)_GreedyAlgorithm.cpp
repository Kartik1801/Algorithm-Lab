#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class item{
    public:
    int value;
    int weight;
    item(){
        value = 0;
        weight = 0;
    }
    item(int value, int weight){
        this->value = value;
        this->weight = weight;
    }
};
bool compare(item I1,item I2){
    return ((float)I1.value/I1.weight >= (float)I2.value/I2.weight);
}
int fractionalKapsack(item I[], int W, int n){
    float maxprofit=0;
    sort(I,I+n,compare);
    for (int i = 0; i < n ; i++){
        if(W>0&&I[i].weight<=W){
            maxprofit+=I[i].value;
            W-=I[i].weight;
        }
        else{
            if(W>0){
                maxprofit+=(float)W*((float)I[i].value/I[i].weight);
                W-=W;
            }
        }
    }
    return maxprofit;
}
int main(){
    item I[4]={{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(I)/sizeof(I[0]);
    int W=50;
    cout<<"Max Profit: "<<fractionalKapsack(I,W,n)<<endl;
    return 0;
}