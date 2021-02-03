#include <bits/stdc++.h>
using namespace std;

int coinChangePermutation(vector<int> arr,int tar,vector<int> dp){  
    if(tar==0){
        return dp[tar] = 1;
    }

    if(dp[tar]!=0) return dp[tar]; 

    int count=0;
    for(int ele: arr){
        if(tar-ele>=0){
            count+=coinChangePermutation(arr,tar-ele,dp);
        }
    }

    return dp[tar] = count;
}

int coinChangePermutation_DP(vector<int> arr,int tar,vector<int> dp) 
{ 
    int Tar=tar;
    dp[0] = 1; 
    for( tar=0;tar<=Tar;tar++)
        for(int ele: arr)
        {
            if(tar-ele>=0)
            {
                dp[tar]+=dp[tar-ele];
            }
        }
    return dp[Tar];
}

int coinChangeCombination(vector<int> arr,int tar,int idx){
    if(tar==0){
        return 1;
    }

    int count=0;
    for(int i=idx;i<arr.length;i++){
        if(tar-arr[idx]>=0){
            count+=coinChangeCombination(arr,tar-arr[idx],i);
        }
    }

    return count;
}

int coinChangeCombination_DP(vector<int> arr, int tar, vector<int> dp)
{
    int Tar = tar;
    dp[0] = 1;
    for (int ele : arr)
        for (tar = ele; tar <= Tar; tar++)
            if (tar - ele >= 0)
                dp[tar] += dp[tar - ele];
    return dp[Tar];
}
