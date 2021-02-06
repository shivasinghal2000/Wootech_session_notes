class compare
{
public:
    bool operator()(const pair<int, int> a, const pair<int, int> b)
    {
        int r1 = a.first;
        int c1 = a.second;
        int r2 = b.first;
        int c2 = b.second;
        return (r1 * r1 + c1 * c1) < (r2 * r2 + c2 * c2);
    }
};
vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (int i = 0; i < points.size(); i++)
    {
        pq.push({points[i][0], points[i][1]});
        if (pq.size() > k)
            pq.pop();
    }
    vector<vector<int>> ans;
    while (k--)
    {
        int r = pq.top().first;
        int c = pq.top().second;
        ans.push_back({r, c});
        pq.pop();
    }
    return ans;
}