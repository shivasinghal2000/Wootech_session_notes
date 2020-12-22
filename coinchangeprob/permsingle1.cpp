#include <iostream>
#include <vector>
using namespace std;
void permutationSingleCoin(vector<int> &arr, int tar, string ans, vector<bool>&vis)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (vis[i] == false && tar - arr[i] >= 0)
        {
            int temp = arr[i];
            vis[i] = true;
            permutationSingleCoin(arr, tar - temp, ans + to_string(temp) + " ",vis);
            // vis[i] = false;
        }
    }
    return;
}

int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    vector<bool> vis(4,false);// none of them is visited intially
    permutationSingleCoin(arr, tar, "",vis);
    return 0;
}