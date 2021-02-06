string frequencySort(string s)
{
    unordered_map<char, int> map;
    for (char ch : s)
        map[ch]++;

    priority_queue<pair<int, char>> pq;

    for (auto key : map)
    {
        pq.push({key.second, key.first});
    }

    string ans = "";
    while (pq.size() != 0)
    {
        pair<int, char> key = pq.top();
        pq.pop();
        int freq = key.first;
        char ch = key.second;

        for (int i = 0; i < freq; i++)
            ans += ch;
    }

    return ans;
}