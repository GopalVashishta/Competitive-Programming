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
        ll n; cin >> n;
        ll cnt2 =0, cnt3 = 0;

        while(n>0 && n%3==0){
            cnt3++;
            n /= 3;
        } // cnt all 3s

        while(n>0 && n%2 == 0){
            cnt2++;
            n /= 2;
        } // cnt 2s, 
        
        // for a no. to be completely div by 6 its factor should like No(2s) == No(3s)
        if(n>1 || cnt2 > cnt3){ // other odd factors than 3 OR it's 2s > 3s so after all div by 6 we have some 2 factor rem
            coutn(-1); // not possible
        }
        else {
            coutn(cnt3 + (cnt3-cnt2)); // cnt3s div 6 oprs + cnt3-cnt2(the amt of 2s to be added)
        }
    }
    return 0;
}