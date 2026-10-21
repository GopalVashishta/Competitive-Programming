#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        vector<int> arr(n);
        unordered_map<int, ll> mp;
        ll mx_freq = 0; // find max frequency
        for(auto &x: arr){
            cin >> x;
            mp[x]++;
            mx_freq=max(mx_freq, mp[x]);
        }
        
        ll opr = 0;
        while(mx_freq<n){
            // simulating that we clone array & move all ele(mx_freq ele) into the main one
            opr++; // creating copy of array

            if(mx_freq*2 <= n){// if we need all the ele from the copy arr, we take
                opr+=(mx_freq);// swap elements
                mx_freq*=2; // now the freq of mx_freq ele has doubled in d main array
            }
            else{
                opr+=(n-mx_freq); // we dont need all ele but a few ele from copy arr 
                mx_freq=n; // now all the elements are the same
            }
        }
        coutn(opr);
    }
    return 0;
}