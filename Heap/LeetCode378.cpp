int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int m = matrix[0].size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < n; i++)
        pq.push({matrix[i][0], i, 0});
    while (k-- > 1)
    {
        vector<int> rvtx = pq.top();
        pq.pop();
        int r = rvtx[1];
        int c = rvtx[2];
        if (c + 1 < m)
            pq.push({matrix[r][c + 1], r, c + 1});
    }

    return pq.top()[0];
}