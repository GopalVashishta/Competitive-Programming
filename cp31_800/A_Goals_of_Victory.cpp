#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> arr(n); 
        long long sum  = 0;
        for(int i=0; i<n-1; i++) { cin >> arr[i]; sum+=arr[i];} // eff of n-1 teams
        // if X team scores against team Y,
        // efficient of X ++
        // and effi of Y--
        // implying if overall was V, then 1st inc and others dec, making overall V again
        // sum = a1+a2+a3+a4 => a4 = sum(0) - (a1+a2+a3);
        // so Effi(n-1) == sum(0) - (sum(all))

        cout << -sum << "\n";

    }
}