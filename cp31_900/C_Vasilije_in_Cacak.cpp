#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        ll n, k, x; cins(n, k, x);
        // ARG: if x <= maxsum && x>=minsum ans is YES
        ll minsum = k*(k+1)/2; // first k elements sum
        // max is sum of last k elements
        ll maxsum = n*(n+1)/2 - (n-k)*(n-k+1)/2; // basically like prefix sum of a range sum(r) - sum(l)
        if(x>=minsum && x<=maxsum) coutn("YES");
        else coutn("NO");
    }
    return 0;
}