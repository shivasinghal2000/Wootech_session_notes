#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/gold-mine-problem/0

int goldmineProblem(vector<vector<int>> grid, int sr, int sc, vector<vector<int>> dp)
{
    if (sc == grid[0].size() - 1)
        return grid[sr][sc];
    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    vector<vector<int>>  dirA = { { 0, 1 }, { -1, 1 }, { 1, 1 } };
    int maxCoin = 0; // max coin collected by nbrs.
    for (int d = 0; d < 3; d++) {
        int r = sr + dirA[d][0];
        int c = sc + dirA[d][1];
        if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()) {
            maxCoin = max(maxCoin, goldmineProblem(grid, r, c, dp));
        }
    }
    return dp[sr][sc] = maxCoin + grid[sr][sc];
}

int goldmineProblem_DP(vector<vector<int>>  grid, int sr, int sc, vector<vector<int>>  dp) {

    vector<vector<int>>  dirA = { { 0, 1 }, { -1, 1 }, { 1, 1 } };
    for (sc = grid[0].size() - 1; sc >= 0; sc--) 
    {
        for (sr = grid.size() - 1; sr >= 0; sr--) 
        {
            if (sc == grid[0].size() - 1) 
            {
                dp[sr][sc] = grid[sr][sc];
                continue;
            }
            int maxCoin = 0; // max coin collected by nbrs.
            for (int d = 0; d < 3; d++) 
            {
                int r = sr + dirA[d][0];
                int c = sc + dirA[d][1];
                if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()) 
                {
                    maxCoin =max(maxCoin, dp[r][c]);
                }
            }
            dp[sr][sc] = maxCoin + grid[sr][sc];
        }
    }
    int MaxCoins = 0;
    for (int i = 0; i < grid.size(); i++) {
        MaxCoins = max(MaxCoins, dp[i][0]);
    }
    return MaxCoins;
}

int goldmineProblem(vector<vector<int>> grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));

    int MaxCoins = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        MaxCoins =max(MaxCoins, goldmineProblem(grid, i, 0, dp));
    }

    return MaxCoins;
}
