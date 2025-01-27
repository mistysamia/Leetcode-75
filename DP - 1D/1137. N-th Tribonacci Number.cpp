class Solution {
public:
    int dp[40];

    int tribonacci(int n) {
        memset(dp, -1, sizeof dp);
        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};