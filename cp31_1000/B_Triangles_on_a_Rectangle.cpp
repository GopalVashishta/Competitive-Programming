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

        // ARG: area = 1/2 *b *h, we have to return 2*area = b*h , we have to maximize b*h
        // for b we for each side we find the left most & right(already ASC) most pt to maximize area(abs(l-r) == Maxbase)
        // for maximizing height we can just take the opposite side(we dont need the pt from opp side cuz thats slant not height)
        // we make 4 cases top bottom left right

        ll w, h; cins(w, h);
        ll area = INT_MIN;
        for(int i=0; i<4; i++) { // top , bottom, left, right side each time
            ll k; cin >> k;
            ll first, last;
            for(int j=0; j<k; j++) { // inpt is already given sorted order
                ll x; cin >> x;
                if(j == 0) first = x;
                if(j == k-1) last = x;
            }

            ll base = last - first;
            ll height = (i<=1) ? h: w; // if 0 or 1 height is h , if  2/3 ht is  w

            area = max(area, base * height); // i.e 2 * (1/2 b*h) = b*h;
        }
        coutn(area);
    }
    return 0;
}