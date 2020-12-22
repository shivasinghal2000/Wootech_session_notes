#include <iostream>
#include <vector>
using namespace std;
void combinationSingleCoin(vector<int> &arr, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return;
    }

    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        combinationSingleCoin(arr, i + 1, tar - arr[i], ans + to_string(arr[i]) + " ");
    }
    return ;
}


int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    combinationSingleCoin(arr, 0, tar, "") ;
    return 0;
}