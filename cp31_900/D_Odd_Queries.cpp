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
        int n,q; cins(n, q);
        vector<int> arr(n); cinv(arr);
        vector<int> pref(n+1, 0); // build prefix 

        for(int i=1; i<=n; i++){
            pref[i] = pref[i-1] + arr[i-1];
        }
        int totsum = pref[n];
        while(q--){
            int l, r,k; cins(l, r, k);
            ll kreplacesum = (r-l+1)*k; // the sum of the segment after replacing all with k
            ll newsum = totsum - (pref[r]- pref[l-1])+ kreplacesum;
            cout << ((newsum&1) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}