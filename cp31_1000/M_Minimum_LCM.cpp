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
        ll n; cin >> n;
        ll a = 1, b = n-1;
        // Conditions by observations:
        // a<=b & b<= n-1 , b >= n/2
        // b%a == 0, n%a == 0 -> that n & b should be multiple of a so is a factor(so we can do it in sqrt)

        for(ll i=2; i*i <= n; i++){
            if(!(n%i)) { 
                a = n/i; // will give the larger number of a+b
                b = n-a; // the other num cuz a+b =n -> b =n-a
                break; 
            } 
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}