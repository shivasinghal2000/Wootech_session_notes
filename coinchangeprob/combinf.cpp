#include <iostream>
#include <vector>
using namespace std;
int combinationINFI(vector<int> &arr, int idx, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count=0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
           count+= combinationINFI(arr, i, tar - arr[i], ans + to_string(arr[i]) + " ");
    }
    return count;
}

int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    cout<<"Count = "<<combinationINFI(arr, 0, tar, "") ;
    return 0;
}