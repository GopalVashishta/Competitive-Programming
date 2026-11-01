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
       ll a, b; cins(a, b); // doing b+1 is better however we have to balance with  a/b too 

       ll ans = INT_MAX;
       for(int ad = 0; ad<32; ad++){
            ll ops = ad;
            ll new_b = b + ops; // for each new b check which is lower
            if(new_b == 1) {
                continue;
            }
            ll copy_a = a;
            while(copy_a >0){ // check how many ops with this b
                copy_a /= new_b;
                ops++;
            }
            ans = min(ans, ops); // store the min ans
       }
       coutn(ans);
    }
    return 0;
}