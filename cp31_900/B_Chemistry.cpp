#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int main() {
    fast;
    int tc; cin>> tc;
    while(tc--){
        int n, k; cins(n, k);
        string s; cin >> s;
        // ARG: if freq(oddOccurance) > k+1 , Then NO
        vector<int> freq(26, 0);// only smaller alphabets
        for(auto c: s) freq[c-'a']++;

        ll odd =0;
        for(auto x: freq) odd+=(x&1);

        if(odd>k+1) coutn("NO");
        else coutn("YES");
    }
    return 0;
}