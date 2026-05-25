#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        long long a, b, c; 
        cin >> a >> b >> c;
        // optimally to exhaust the other player out, both will finish the c first
        if(c&1){// if C odd the next player is Katie
            if(b>a) cout << "Second" << "\n";
            else cout << "First" << "\n";
        }
        else { // if C even next player is Ana
            if(a>b) cout << "First" << "\n";
            else cout << "Second" << "\n";
        }
    }
    return 0;
}