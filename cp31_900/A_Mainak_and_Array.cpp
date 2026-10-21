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
        vector<int> arr(n); cinv(arr);
        // ## Failed Approach: maxVal - minVal

        // Case 1: we Fix 0th ix element and can rotate 1 to (n-1) elements, a[i]-a[0] here i>1
        // Case 2: We fix n-1th element and can rotate 0 to (n-2) elements, a[n-1]-a[i] here i<n
        // Case 3: We can rotate the whole array 0 to (n-1), here for each k the ans will be arr[i]-arr[i+1]
        // Case3(expln for above): the last element'll bcm 1st and 2nd last is last now, we can do rotation n times

        int ans = arr[n-1]-arr[0]; // if already sorted 
        
        for(int i=1; i<n; i++) // Case 1
            ans = max(ans, arr[i]-arr[0]);

        for(int i=0; i<n-1; i++){ // Case 2
            ans = max(ans, arr[n-1]-arr[i]);
            ans = max(ans, arr[i]-arr[i+1]); // Case 3
        }
        coutn(ans);
    }
    return 0;
}