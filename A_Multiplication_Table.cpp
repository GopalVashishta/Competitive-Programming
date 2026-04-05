#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    int cnt =0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {  
            int j = x / i;  
            if (i <= n && j <= n) {
                cnt++;  
                if (i != j) {
                    cnt++;  
                }
            }
        }
    }
    cout<<cnt<<" ";
}