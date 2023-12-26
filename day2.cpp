#include <iostream>
#include <vector>

using namespace std;

int numRollsToTarget(int n, int k, int target) {
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: there is one way to get a sum of 0 with 0 dice
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            for (int face = 1; face <= k; ++face) {
                if (j - face >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                }
            }
        }
    }

    return dp[n][target];
}

int main() {
    int t;
    cin>>t;
    while(t--){ 
    int n ;
    cin>>n;

    int k ;
    cin>>k;
    int target ;
    cin>>target;
    int result = numRollsToTarget(n, k, target);
    cout << result << endl;
}
    return 0;
}