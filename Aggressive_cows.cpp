#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
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

#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int placecows(ll mid, int c, vector<int> &cows){
    int cnt = 1, last = cows[0];
    for(int i =1; i<(int)cows.size(); i++){
        if(cows[i] - last >= mid){
            cnt++; last = cows[i];
        }
    }
    return cnt>=c;
}
int main() {
    fast;
    int t; cin >> t;
    while(t--){
        int n,c; cins(n,c);
        vector<int> loca(n); cinv(loca);
        sort(loca.begin(), loca.end());
        long long l = 1, r = loca[n-1] - loca[0];
        while(l<=r){
            long long mid = (l+r)/2;
            if(placecows(mid,c,loca)){
                l = mid+1;
            }
            else r = mid-1;
        }
        coutn(r);
        
    }
    return 0;
}