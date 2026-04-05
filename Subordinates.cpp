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
#include <string>
#include <cmath>
#include <math.h>
#include <numeric>
#include <iomanip>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int dfs(int v, const vector<vector<ll>> &tree, vector<ll> &subcnt) {
    int cnt = 0;
    for (int u : tree[v]) {
        cnt += 1 + dfs(u, tree, subcnt);
    }
    subcnt[v] = cnt;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<vector<ll>> tree(n);
    for (int i = 1; i < n; ++i) {
        ll boss; cin >> boss;
        tree[boss - 1].push_back(i);
    }
    vector<ll> subcnt(n, 0);
    dfs(0, tree, subcnt);
    for (int i = 0; i < n; ++i) cout << subcnt[i] << " ";
    cout << '\n';
    return 0;
}