#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <cmath>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)


using ld = long double;
using ll = long long;

int main() {
    fast;
    int tc; cin >> tc;
    // Yuri -1 from left
    // Iskendra -1 from right
    while(tc--){
        ll n; cin >> n;
        string s; cin >> s;
        ll fs = s[0] == '#' ? 1: -100;
        // Kandane algo, subarray with max no. of #
        ll cursm = fs, mx = fs;
        for(ll i=1; i<n; i++){
            ll val = s[i] == '#' ? 1: -100;
            cursm = max(cursm+val,val);
            mx = max(cursm, mx);
        }
        cout << ((mx < 0) ? 0 : ceil((double)mx/2)) << " \n";
    }
    return 0;
}