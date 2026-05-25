#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc; cin >> tc;
    int score[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, 
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1}, 
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1}, 
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1}, 
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1}, 
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1}, 
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} 
    };
    while(tc--){
        vector<pair<int, int>> pos;
        long long ans = 0;
        for(int i=0; i<10; i++){
            string s; cin >> s;
            for(int j=0; j<s.length(); j++) if(s[j] == 'X') ans += score[i][j];
        }
        cout << ans << "\n";
    }
    return 0;
}