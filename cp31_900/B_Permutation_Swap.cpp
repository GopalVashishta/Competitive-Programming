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
        int k = abs(arr[0]-1);
        for(int i=1; i<n; i++){
            k = gcd(k, abs(arr[i]-(i+1)));// Bhagwaan jane kaha se gcd le aya banda(TLE elim)
        }
        coutn(k);
    }
    return 0;
}