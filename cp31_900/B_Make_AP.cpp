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
        ll a, b, c; cins(a, b, c);
        bool ans = false;
        // try to find m for all cases, where we mlt m with all 3

        // we try to find a*m, b-am = c-b
        ll new_a = 2*b-c;
        // should be +ve & divisble by a cuz its a*m
        if(new_a/a >0 && new_a%a == 0) ans = true;

        // b*m, bm-a = c-bm
        ll new_b = (a+c)/2;
        if(new_b/b >0 && new_b%b ==0 && (c-a)%2 == 0) ans = true;

        // c*m, b-a = cm-b
        ll new_c = 2*b-a;
        if(new_c/c >0 && new_c%c ==0 ) ans = true;
        
        coutn(ans?"YES":"NO");
    }
    return 0;
}