#include<bits/stdc++.h>
using namespace std;    

int main(){
    int n;
    cin>>n;
    vector<int> arr(n-1);
    for(int i = 0; i < n - 1; i++){
        cin>>arr[i];
    }
    int xor1 = 0, xor2 =0;
    for(int i=0; i<n-1; i++){
        xor1 = xor1^arr[i];
        xor2 = xor2^(i+1);
    }
    xor2 = xor2^n; 
    cout<<(xor1^xor2);

}