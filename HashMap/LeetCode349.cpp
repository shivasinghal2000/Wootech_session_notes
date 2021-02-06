vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    unordered_set<int> map;

    for (int i = 0; i < nums1.size(); i++)
        map.insert(nums1[i]);
    for (int i = 0; i < nums2.size(); i++)
    {
        if (map.find(nums2[i]) != map.end() && find(ans.begin(), ans.end(), nums2[i]) == ans.end())
            ans.push_back(nums2[i]);
    }
    return ans;
}