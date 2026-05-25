#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n; cin >> n;
        int maxSum = 0;
        int bestX = 2;

        for (int x = 2; x <= n; ++x) {
            int k = n / x; 
            
            int currentSum = x * (k * (k + 1) / 2); // x*(sum of n natural no.)

            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestX = x;
            }
        }
        cout << bestX << "\n";
    }
}