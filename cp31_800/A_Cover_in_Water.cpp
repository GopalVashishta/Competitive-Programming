#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        string s; cin >> s;
        int cnt =0; bool cont_3_cells=false;
        // if 3 cont cell exist we can use operation2 to fill the rest so ans is 2
        // if not then ans is cnt of all empty cells
        for(int i=0; i<n; i++){
            if(s[i] == '.' && i+1 <n && i+2 <n && s[i+1] == '.' && s[i+2] == '.'){ cont_3_cells = true; break;}
            if(s[i] == '.') cnt++;
        }
        if(cont_3_cells){
            cout << 2 << "\n"; continue;
        }
        cout << cnt << "\n";
    }
}