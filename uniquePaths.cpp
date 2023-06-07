int uniquePaths(int m, int n) {
    // Create a 2D grid to store the number of unique paths
    vector<std::vector<int>> dp(m, vector<int>(n, 0));

    // There is only one way to reach any cell in the first row or first column
    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    // Fill in the number of unique paths for each cell
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            // The number of unique paths to reach the current cell is the sum of
            // the number of unique paths from the cell above and the cell to the left
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // The number of unique paths to reach the bottom-right cell is stored in dp[m-1][n-1]
    return dp[m - 1][n - 1];
}
