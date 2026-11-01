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
    ll n, d; cins(n, d);
    vector<ll> arr(n); cinv(arr);

    sort(arr.begin(), arr.end());
    
    ll l = -1, r = n-1; // if array size is 1 the loop never executes, thats why l is -1
    ll ans =0, teamsz=1;
    while(l<r){
        if(arr[r]*teamsz <=d && l<r) { // while small the tot pow < D, we add more members
            l++;
            teamsz++;
        }
        else {
            ans++;
            r--; // now lets move to create next team with highest pow of curr R ix
            teamsz = 1; // r always part of team
        }
    }
    coutn(ans);
    return 0;
}