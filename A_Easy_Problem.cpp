#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int cnt = 0, n; cin >> n;
        for(int b=1; b<n; b++){
            int a = n-b;
            if(a > 0) cnt++;
        }
        cout << cnt << "\n";
    }
}