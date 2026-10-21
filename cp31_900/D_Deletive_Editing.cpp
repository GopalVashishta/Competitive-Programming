#include <bits/stdc++.h>
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

int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        string s, t; cins(s, t);
        int m = t.length(), n = s.length();

        vector<int> fr(26, 0);
        for(auto x: t) fr[x-'A']++;

        for(int i=n-1; i>=0; i--){
            if(fr[s[i]-'A'] > 0)// if we can tak use it
                fr[s[i]-'A']--;

            else s[i] = '.'; // if occur 0, we dont need it mark it
        }

        string final_str = "";
        for(int i=0; i<n; i++){
            if(s[i] != '.') // create the string from all last occur of letters
                final_str+=s[i];
        }
        
        if(final_str == t) coutn("YES");
        else coutn("NO");
    }
    
    return 0;
}