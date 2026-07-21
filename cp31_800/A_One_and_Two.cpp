#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <cmath>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
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
        vector<ll> arr(n);
        //ll mlt =1; // did by doing multiplication but got runtime error

        ll twoCnt = 0;
        for(auto &x: arr){ 
            cin >> x; 
            if(!(x&1)) twoCnt++;
            //mlt*=x; 
        }
        if(twoCnt&1){
            cout << "-1" << "\n"; continue;
        }
        ll ix = 0;
        ll tar = twoCnt>>1;

        for(ix; ix<n; ix++){
            if(!(arr[ix]&1)) twoCnt--;
            if(twoCnt == tar) { cout << ix+1 << "\n"; break; }
        }
    }
    return 0;
}