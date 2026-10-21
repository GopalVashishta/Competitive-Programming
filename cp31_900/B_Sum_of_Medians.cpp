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
        int n, k; cins(n, k);
        ll ans =0;
        vector<ll> arr(n*k);
        cinv(arr);
        // most preferbly watch the TLE video
        // if the segment has K elements u choose (right)k-1 elements from the orignal order of input
        // however the smallest/1st element of that segment can be taken from 1st segement(it has smalles nums as original inp is non-dec)
        // so we try to maximize median like that

        ll ptr = n*k;
        while(k--){
            ptr -= (n/2 +1);
            ans += arr[ptr];
        }
        coutn(ans);
    }
    return 0;
}