#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n, x; cin >> n >> x;
        vector<int> stations(n);
        for(auto &x: stations) cin >> x;
        
        int ans = max(stations[0], 2*(x-stations[n-1])); // from 0->1st staion OR last->x->last coz cant refuel at last
        for(int i=1; i<n; i++){
            ans = max(ans, stations[i]-stations[i-1]);// check dist for each consecutive gas station
        }
        cout << ans << "\n";
    }
    return 0;
}