#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc; 
    cin>>tc;
    while(tc--){
        int n ,s; cin>>n>>s;
        vector<int> v(n);
        int mn = INT_MAX, mx = INT_MIN;
        for(int i =0; i<n; i++) { cin>>v[i]; mn = min(v[i], mn); mx = max(v[i], mx); }
        
        cout<< mx - mn + min(abs(s-mn), abs(s-mx)) <<"\n";  // R-L + min(abs(s-mn), abs(s-mx));
    }
}