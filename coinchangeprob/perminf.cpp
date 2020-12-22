#include <iostream>
#include <vector>
using namespace std;
int permutationINFI(vector<int> &arr, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
      count+=permutationINFI(arr, tar - arr[i], ans+ to_string(arr[i]) + " ");
    }
    return count;
}
int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    cout<<"count= "<<permutationINFI(arr, tar, "")<<endl;
    return 0;
}
// timecomplexity = k*n  