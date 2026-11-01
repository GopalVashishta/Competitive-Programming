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
    ll tc; cin >> tc;

    while(tc--){
        ll n, k; cins(n, k);
        string s; cin >> s;
        // ARG: The segment with lowest white cnts is the ans

        ll wcnt = 0;
        
        for(int i = 0; i < k; i++) {
            if (s[i] == 'W')
                wcnt++;
        }
        ll mncnt = wcnt;

        for (int i = k; i < n; i++) {
            if (s[i] == 'W') wcnt++;
            if (s[i - k] == 'W') wcnt--;

            mncnt = min(mncnt, wcnt);
        }
        coutn(mncnt);
    }
    return 0;
}