int edit_dis(string a, string b) {
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 0; i <= a.size(); i++)dp[i][0] = i;
    for (int i = 0; i <= b.size(); i++)dp[0][i] = i;

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            int change_cost = dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, change_cost});
        }
    }

    return dp[a.size()][b.size()];
}
