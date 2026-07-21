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

int play(int l, int r, int turn, vector<vector<int>> &dp, vector<int> &arr){
    if(l>r) return INT_MIN;

    int ltak = arr[l] - play(l+1, r, !turn, dp, arr);
    int rtak = arr[r] - play(l, r-1, !turn, dp, arr);

    return dp[]
}
int main() {
    fast;
    int n; cin >> n;
    vector<int> arr(n); cinv(arr);
    vector<vector<int>> dp(n, vector<int>(2, -1));
    coutn(play(0, n-1, 0, dp, arr));
    return 0;
}