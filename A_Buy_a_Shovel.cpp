#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, r;
    cin >> k >> r;
    int burel = 10, i=1;
    while(true){
        int val = (k*i)%burel;
        if( val == 0 || val == r){
            cout << i; break;
        }
        i++;
    }
    return 0;
}