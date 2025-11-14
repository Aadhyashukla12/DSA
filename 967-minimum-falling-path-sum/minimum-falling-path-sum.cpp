class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        for (int j = 0; j < n; j++)
            dp[0][j] = a[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int ld = (j > 0 ? dp[i-1][j-1] : 1e9);
                int rd = (j < n-1 ? dp[i-1][j+1] : 1e9);
                dp[i][j] = a[i][j] + min(up, min(ld, rd));
            }
        }

        int ans = 1e9;
        for (int j = 0; j < n; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};
