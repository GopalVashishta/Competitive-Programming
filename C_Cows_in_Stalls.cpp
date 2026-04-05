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

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int cows(int mid, int cws, vector<int> &arr){
    int cw = 1, prev = arr[0];
    int n = arr.size();
    for(int i = 1; i<n; i++){
        if(arr[i]-prev >= mid){
            cw++; prev = arr[i]; 
            if(cw >= cws) return true;
        }
       
    }
    return cw >= cws;
}

int main() {
    fast;
    int n,c; cins(n,c);
    vector<int> arr(n); cinv(arr);
    int l = 1, r = arr[n-1] - arr[0];
    int ans = 1;
    while(l<=r){
        int mid = (l+r)/2;
        if(cows(mid,c,arr)){
            ans = mid; l = mid+1;
        }
        else r = mid-1;
    }
    coutn(ans);
    return 0;
}