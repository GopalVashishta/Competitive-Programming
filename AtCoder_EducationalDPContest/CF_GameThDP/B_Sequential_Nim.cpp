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

int plays(int ix, int val, const vector<int> &arr){
    if(ix<0) return 0; // Looses

    if(!val) return plays(ix-1, ix>0?arr[ix-1]:0, arr);

    for(int i=1; i<=val; i++){
        if(!plays(ix, val-i, arr)) return 1; // If Opp looses only then
    }

    return 0; // if they win all the time then we lose
}
int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        int n; cin >>n; 
        vector<int> arr(n); cinv(arr);
        coutn(plays(n-1, arr[n-1], arr) ? "First" : "Second");
    }
    
    return 0;
}