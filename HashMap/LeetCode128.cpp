int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> map;
    for (int ele : nums)
        map.insert(ele);
    int len = 0;

    for (int ele : nums)
    {

        if (map.find(ele) == map.end())
            continue;

        map.erase(ele);
        int prev = ele - 1;
        int next = ele + 1;

        while (map.find(prev) != map.end())
        {
            map.erase(prev);
            prev--;
        }

        while (map.find(next) != map.end())
        {
            map.erase(next);
            next++;
        }

        len = max(len, next - prev - 1);
    }

    return len;
}