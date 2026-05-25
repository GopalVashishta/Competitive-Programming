#include<bits/stdc++.h>
using namespace std;

int main() {
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> nums(n);

        long seen = 0; // hashmap kinda stuff using bits
        bool fg = false;
        for(auto &x: nums) { 
            cin >> x;
            if((seen & (1<<x))) { // if already seen the ans is NO
                fg = true;
                break;
            }
            seen = seen | (1 << x); // mark as seen
        }
        if(fg || nums[0] != 1) { // if duplicated or the first ix val not 1(read ques)
            cout << "NO" << "\n";
        }
        else {
            cout << "YES" << "\n";
        }
    }
    return 0;
}