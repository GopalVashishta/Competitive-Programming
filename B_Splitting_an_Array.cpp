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
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

bool canDivide(const vector<int>& a, int k, ll max_sum) {
    int segments = 1;
    ll current_sum = 0;
    for (int num : a) {
        if (current_sum + num > max_sum) {
            segments++;
            current_sum = num;
            if (segments > k) return false;
        } else {
            current_sum += num;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0, max_elem = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        max_elem = max(max_elem, 1LL * a[i]);
    }

    ll low = max_elem, high = sum, ans = sum;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canDivide(a, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    coutn(ans);
    return 0;
}
