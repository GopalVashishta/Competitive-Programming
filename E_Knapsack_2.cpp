#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const long long INF = 1e18;
//imp knapSack
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long W;
    cin >> N >> W;

    vector<int> w(N);
    vector<int> v(N);
    int total_max_value = 0;

    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
        total_max_value += v[i];
    }

    vector<long long> dp(total_max_value + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i) {
        int current_weight = w[i];
        int current_value = v[i];

        for (int val = total_max_value; val >= current_value; --val) {
            if (dp[val - current_value] != INF) {
                dp[val] = min(dp[val], dp[val - current_value] + current_weight);
            }
        }
    }

    long long max_achievable_value = 0;
    for (int val = total_max_value; val >= 0; --val) {
        if (dp[val] <= W) {
            max_achievable_value = val;
            break;
        }
    }

    cout << max_achievable_value << endl;

    return 0;
}