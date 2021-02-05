// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/
#include <bits/stdc++.h>
using namespace std;

int count_of_ways(int n, int k, vector<vector<int>>& dp) {
    if (k == n || k == 1)
        return dp[k][n] = 1;

    if (dp[k][n] != -1)
        return dp[k][n];

    int ownGroup = count_of_ways(n - 1, k - 1, dp);
    int partOfOtherGroup = count_of_ways(n - 1, k, dp) * k;

    return dp[k][n] = ownGroup + partOfOtherGroup;
}

int count_of_ways_DP(int n, int k, vector<vector<int>> &dp)
{
    int K = k;
    int N = n;
    for (k = 1; k <= K; k++)
    {
        for (n = k; n <= N; n++)
        {
            if (k == n || k == 1)
            {
                dp[k][n] = 1;
                continue;
            }

            int ownGroup = dp[k - 1][n - 1];         // count_of_ways(n - 1, k - 1, dp);
            int partOfOtherGroup = dp[k][n - 1] * k; // count_of_ways(n - 1, k, dp) * k;

            dp[k][n] = ownGroup + partOfOtherGroup;
        }
    }

    return dp[K][N];
}

void count_of_ways(int n, int k) {
    vector<vector<int>> dp(k+1,vector<int>(n+1,-1)); 

    // cout<<(count_of_ways(n, k, dp))<<endl;
    cout << (count_of_ways_DP(n, k, dp)) << endl;
}

int main()
{
    count_of_ways(5,2);
}