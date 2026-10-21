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
        ll n; cin >> n;
        // Failed Approach: Brute for Maths for below
        // for MinBuses: we try to maximize 3xl, for MaxBuses: we try to maximize 2xl buses

        if(n&1 || n<4){ // cant make buses with given wheels(odd) & cant make any buses cuz atleast 4 wheels req.
            coutn(-1);
            continue;
        }
        
        // now n is even
        //ceil(n*1.0/6); had some precision problems
        ll minbuses = (n + 5) / 6;//if n%6== 0/2/4, if 0 no 2xl, if 2 take 6 from 3xl->make 2 2xl, If 4 then make a 2xl 
        ll maxbuses = n/4; //if n%4== 0/2, if 0 then no 3xl, if 2 then take 4 wheels from 2xl->make 1 3xl

        couts(minbuses, maxbuses);
        cout << "\n";
    }
    return 0;
}