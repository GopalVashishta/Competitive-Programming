#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        long long n, k; cin >> n >> k;
        // Getting a TLE on TC 6 if shirking window i.e j = m-1; while(...) j--;
        vector<long long> zos;
        long long cnt =0;
        for(int i=0; i<n; i++){
            char c; cin >> c;
            if(c == 'B') zos.push_back(i); // save only the indecies of B's
        }
        int m = zos.size();
        for(long long i=0; i<=m-1;){ // go till end
            long long j = i; // start from the last
            while(j<m && zos[j]-zos[i]+1 < k) j++; // expand till we get max valid window
            i= (zos[j]-zos[i]+1 > k) ?  j: j+1; // update i // fixed it 
            cnt++; // count each
        }
        cout << cnt << "\n";
    }
}