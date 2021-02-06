class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end())
            {
                int index = map[nums[i]];
                if (i - index <= k)
                    return true;
                map[nums[i]] = i;
            }
            else
                map.insert({nums[i], i});
        }

        return false;
    }
};