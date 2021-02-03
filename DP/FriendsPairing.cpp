#include <bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0

long friendsPairingProblem(int n, vector<long> dp)
{
    if (n <= 1)
        return dp[n] = 1;
    if (dp[n] != 0)
        return dp[n];

    long single = friendsPairingProblem(n - 1, dp) % mod;
    long pairUp = friendsPairingProblem(n - 2, dp) % mod * (n - 1) % mod;
    return dp[n] = (single + pairUp) % mod;
}

long friendsPairingProblem_DP(int n, vector<long> dp)
{
    int N = n;
    for (n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        long single = dp[n - 1] % mod;                 // friendsPairingProblem(n - 1, dp);
        long pairUp = dp[n - 2] % mod * (n - 1) % mod; // friendsPairingProblem(n - 2, dp) * (n - 1);

        dp[n] = single + pairUp;
    }

    return dp[N] % mod;
}
// 0 1 1 2 3
// p s 
//   p s
//     p s
 
int friendsPairingProblem_Opti(int n)
{
    int single = 1;
    int pairUp = 1;

    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = single + pairUp * (i - 1);

        pairUp = single;
        single = ans;
    }

    return ans;
}

void friendsPairingProblem()
{
    // int n = scn.nextInt();
    int n = 5;
    vector<long>dp(n+1);
    long ans = friendsPairingProblem(n, dp);

    cout<<ans<<endl;
}