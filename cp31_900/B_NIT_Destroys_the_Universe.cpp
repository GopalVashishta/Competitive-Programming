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
    ll tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> arr(n); 
        int zeroCnt = 0;
        for(auto &x: arr){
            cin >> x;
            if(!x) zeroCnt++;
        }

        if(zeroCnt == n){ // if all elements are  already 0s
            coutn(0); continue;
        }

        // Failed Approach: Counting Subarrays which doesn't have 0 in it, cuz for that subarr the Mex is 
        
        int l =0, r = n-1;
        while(l<n && arr[l] == 0) l++; // left most non 0 element
        while(r>=0 && arr[r] == 0) r--; // right most non 0 element

        // Case 1: The whole segment(L to R) does not have 0 in it so the Ans is 1
        // Case 2: The L to R segment has 0s in it so we can just apply opr to the whole array 2 times
        //         The first time all n elemnts will be change to some non 0 +ve no.
        //         The Second time we all the n elements will be change to 0 cuz 0 will be the Mex of the whole array 
        bool has0s = false;
        for(int i=l; i<=r; i++){
            if(arr[i] == 0) has0s = true;
        }
        coutn((has0s) ? "2": "1");
    }
    return 0;
}