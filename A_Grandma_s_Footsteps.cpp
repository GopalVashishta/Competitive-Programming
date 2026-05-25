#include <iostream>
#include<algorithm> // for min()
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)


template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}

using ld = long double;
using ll = long long;


int main() {
    fast;
    int s,a,b,x; cins(s,a,b,x);
    long tot = 0;
    while(x){
        int mn = min(a,x);
        tot += s*mn, x-=mn; // updated x with time taken to run
        x-=min(x,b); // update with time taken for stationary
    }
    couts(tot);
    return 0;
}