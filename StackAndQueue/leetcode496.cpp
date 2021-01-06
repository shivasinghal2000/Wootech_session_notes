#include <bits/stdc++.h>
using namespace std;
void findNGE(vector<int> &arr, int n, vector<int> &nge)
{
    // s represents those elements for which nge is yet to be finalised
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }
        while(s.empty() == false && arr[s.top()] < arr[i])
        {
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    while (s.empty() == false)
    {
        nge[s.top()] = -1;
        s.pop();
    }
}
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() == 0)
        return {};
    int n = nums2.size();
    vector<int> nge(n, -1);
    vector<int> ans(nums1.size(), -1);
    if (n == 0)
        return ans;
    findNGE(nums2, n, nge);
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums2[j] == nums1[i])
            {
                ans[i] = nge[j];
                break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}