#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int m; cin >> m;
        vector<int> b(m); for(auto &x: b) cin >> x;


        vector<int> a; a.push_back(b[0]); // first element is always retained
        // if b[i] >= b[i-1] just add this no.
        // if b[i] < b[i-1], there is supposed to be a no. between b[i-1] & b[i]
        for(int i=1; i<m; i++){
            if(b[i] >= b[i-1]) a.push_back(b[i]); // no need to add another, not this only
            else {
                a.push_back(b[i]); a.push_back(b[i]); // there is need of a no., so we add the same no.
            }
        }
        cout << a.size() << "\n";
        for(auto x: a) cout << x << " ";
        cout << "\n";
    }
    return 0;
}