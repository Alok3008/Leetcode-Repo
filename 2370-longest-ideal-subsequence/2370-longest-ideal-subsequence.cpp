class Solution {
public:
    int longestIdealString(string s, int k) {
        int N = size(s);
        vector<vector<int>> dp(N, vector<int>(26, -1));

        int res = 0;
        for (int c = 0; c < 26; c++) {
            res = max(res, dfs(N - 1, c, dp, s, k));
        }
        return res;
    }

    int dfs(int i, int c, vector<vector<int>>& dp, string& s, int k) {
        if (dp[i][c] != -1) {
            return dp[i][c];
        }

        dp[i][c] = 0;
        bool match = c == (s[i] - 'a');
        if (match) {
            dp[i][c] = 1;
        }

        if (i > 0) {
            dp[i][c] = dfs(i - 1, c, dp, s, k);
            if (match) {
                for (int p = 0; p < 26; p++) {
                    if (abs(c - p) <= k) {
                        dp[i][c] = max(dp[i][c], dfs(i - 1, p, dp, s, k) + 1);
                    }
                }
            }
        }
        return dp[i][c];
    }
};