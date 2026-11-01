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
        // ARG: if any shoe sie is uniq, a valid shoe suffle doesnt exist
        ll n; cin >> n;
        unordered_map<ll, ll> frq;
        vector<ll> sizes(n);
        for(auto &x: sizes){
            cin >> x;
            frq[x]++;
        }
        ll fg = 0;
        for(auto &x: frq){
            if(x.second == 1){
                fg = 1; break;
            }
        }
        if(fg) { // if a uniq values exists then not possible, just check a TC
            coutn(-1); continue;
        }

        vector<ll> stdnts(n);
        for(int i=0; i<n; i++)
            stdnts[i] = i+1; // Permuatation array
        
            ll l = 0, r = 0;
            while(r<n){
                if(sizes[l] == sizes[r]) r++; // till we have duplicates
                else { // we have duplicates so we can shuffle b/w duplicate sizes(Permuation array change not the size arr)
                    rotate(stdnts.begin()+l, stdnts.begin()+l+1, stdnts.begin()+r);
                    l = r;
                }
            }
            // doing one last time
            rotate(stdnts.begin()+l, stdnts.begin()+l+1, stdnts.begin()+r);

            for(auto &x: stdnts)
                cout << x << " ";
            cout << "\n";

    }
    return 0;
}