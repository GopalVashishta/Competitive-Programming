#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc; 
    cin>>tc;
    while(tc--){
        int n ,s; cin>>n>>s;
        vector<int> v(n);
        for(int i =0; i<n; i++)
            cin>>v[i];
        int d1 = 0,d2 = n-1;
        int a = s - d1, b= d2-s;
        cout<< 2*(min(a,b) + max(a,b))<<"\n"; 
    }
}