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
       ll n, k, b, s; cins(n, k, b, s);
       // for each b & s there is a max & min range of sum we can make 
       // to make Beauty b i can ALWAYS do array: k*b 0 0 0 0 0.. <- MinSum
       // now to make sum s i can do: k*b (k-1) (k-1) (k-1) (k-1).. so k-1 contrib 0 to beauty <- MaxSum
       ll min_s = k*b;
       ll max_s = min_s + n*(k-1);
       if(s< min_s || s> max_s){ // if out of range sum we can do it
            coutn(-1); continue;
       }
       else {
            vector<ll> ans(n, 0);
            ans[0] = min_s;
            s-=min_s;
            for(int i=0; i<n; i++) {
                ll add = min(k-1, s);
                ans[i] += add;
                s-=add;
            }

            for(const auto &x: ans) cout << x << " ";
            cout << "\n";
       }

    }
    return 0;
}