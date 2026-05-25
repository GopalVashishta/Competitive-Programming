#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    vector<int> a(n), b(m);
    for(auto & x: a) cin>>x;
    for(auto & x: b) cin>>x;
    vector<int> ans(m,0);
    int i = n-1, j = m-1;
    while(j>=0){
        if(b[j] > a[i]){
            ans[j--] = i+1;
        }
        else{
            i--;
            if(i<0) break;
        }
    }
    for(auto x: ans) cout<<x<<" ";
    return 0;
}
