#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int n, m; cins(n, m);
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    vector<int> ans(n+m);
    int i = 0, j = 0, k = 0;
    while(i < n && j < m){
        if(a[i] <= b[j]){
            ans[k++] = a[i++];
        }
        else{
            ans[k++] = b[j++];
        }
    }
    while(i<n) ans[k++] = a[i++];
    while(j<m) ans[k++] = b[j++];

    for(auto x: ans) couts(x);
    
    return 0;
}