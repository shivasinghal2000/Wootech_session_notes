#include <bits/stdc++.h>
using namespace std;

// Left to Right  ---->
int LIS_LR(vector<int> &arr, vector<int> &dp)
{
    int max_ = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i]) // kb consider krege
            {
                dp[i] = max(dp[i], dp[j] + 1); // kb update krege
            }
        }
        max_ = max(max_, dp[i]);
    }
    return max_;
}

//Right to left  <----
int LIS_RL(vector<int> arr,vector<int> dp)
{
    int max_=0;
    for(int i = arr.size()-1; i>=0 ; i--)
    {
        dp[i] = 1;
        for(int j = i+1;j < arr.size();j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        max_=max(max_,dp[i]);
    }
    return max_;
}

// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
int LBS(vector<int> arr)
{
    int n=arr.size();
    vector<int> LIS(n);
    vector<int> LDS(n);

    LIS_LR(arr,LIS);
    LIS_RL(arr,LDS);

    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        int len=LIS[i]+LDS[i]-1;
        maxLen=max(maxLen,len);
    }

    return maxLen;
}


//Maximum Sum Bitonic subsequnece
// Left to Right
int LIS_LR(vector<int> arr,vector<int> dp)
{
    int max_=0;
    for(int i=0;i<arr.size();i++)
    {
        dp[i] = arr[i];
        for(int j = i-1;j>=0;j--)
        {
            if(arr[j] < arr[i])
            {
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
        }
        max_=max(max_,dp[i]);
    }
    return max_;
}

// Right to Left
int LIS_RL(vector<int> arr,vector<int> dp)
{
    int max_=0;
    for(int i = arr.size()-1; i>=0 ; i--)
    {
        dp[i] = arr[i];
        for(int j = i+1;j < arr.size();j++)
        {
            if(arr[j] < arr[i]){
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
        }
        max_=max(max_,dp[i]);
    }
    return max_;
}

int LBS(vector<int> arr)
{
    int n=arr.size();
    vector<int> LIS(n);
    vector<int> LDS(n);

    LIS_LR(arr,LIS);
    LIS_RL(arr,LDS);

    int maxLen=0;
    for(int i=0;i<n;i++)
    {
        int len=LIS[i]+LDS[i]-arr[i];
        maxLen=max(maxLen,len);
    }

    return maxLen;
}

void main()
{
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout<<LBS(arr)<<endl;
}
