#include <iostream>
#include <vector>
using namespace std;
void permutationSingleCoin(vector<int> &arr, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return ;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0 && tar - arr[i] >= 0)
        {
            int temp = arr[i];
            arr[i] = -arr[i];
            permutationSingleCoin(arr, tar - temp, ans + to_string(temp) + " ");
            arr[i] = -arr[i];
        }
    }
    return ;
}

int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    permutationSingleCoin(arr, tar, "");
    return 0;
}