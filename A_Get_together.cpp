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

using ld = double;
using ll = long long;


int n;
vector<pair<ld, ld>> people;

ld time_to_meet(ld p) {
    ld max_time = 0.0;
    for (const auto& [x, v] : people) {
        max_time = max(max_time, abs(x - p) / v);
    }
    return max_time;
}

int main() {
    fast;
    cin >> n;
    people.resize(n);
    ld left = 1e9, right = -1e9;

    for (int i = 0; i < n; ++i) {
        ld x, v;
        cin >> x >> v;
        people[i] = {x, v};
        left = min(left, x);
        right = max(right, x);
    }

    // Ternary search with ~60 iterations is enough
    for (int i = 0; i < 60; ++i) {
        ld m1 = left + (right - left) / 3;
        ld m2 = right - (right - left) / 3;
        if (time_to_meet(m1) < time_to_meet(m2))
            right = m2;
        else
            left = m1;
    }

    ld answer = time_to_meet((left + right) / 2);
    cout << fixed << setprecision(10) << answer << "\n";

    return 0;
}