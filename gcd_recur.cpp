#include<bits/stdc++.h>
using namespace std;

long long gd(long long  a , long long b){
    if(a == 0) return b;
    return gd(b % a, a);
}

int main(){
    long long a, b; 
    cin >> a >> b;
    cout << gd(a, b);
    return 0;
}