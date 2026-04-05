#include<bits/stdc++.h>
using namespace std;
//family tree

int prefixs(int ind, vector<int>& arr){
    long sum = 0;
    while(ind > 0){
        sum += arr[ind];
        ind -=(ind & -ind); // right most bit is calculated here and then subtracted
    }
    return sum;
}
void update(int ind, int v, vector<int>& fenwick){
    int n = fenwick.size():
    while(ind <= n){
        fenwick[ind] += v;
        ind += (ind & -ind);
    }
}
int main(){
    int n ; cin >> n;

}