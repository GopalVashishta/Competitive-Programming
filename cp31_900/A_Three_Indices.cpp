#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> arr(n); cinv(arr);
        /* Brute force
        for(int j=1; j<n-1; j++){
            for(int i=0; i<j; j++) { ... }
            for(int k=k+1; k<n; k++) { ... }
        } 
        */
       // ARG: There should exist a peak of 3 consecutive as its a permutation of ARr
       bool fg = false;
       for(int i=1; i<n-1; i++){
            if(arr[i-1] < arr[i] && arr[i+1] < arr[i]) { // if peak found
                coutn("YES");
                couts(i, i+1, i+2); // 1 based ix
                cout<<"\n";
                fg = true; break; 
            }
       }
       if(!fg) coutn("NO");
    }
    return 0;
}