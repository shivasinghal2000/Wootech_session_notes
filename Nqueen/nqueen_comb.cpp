#include <bits/stdc++.h>
using namespace std;
// Combination of N-queen
bool isSafeToPlaceQueen(vector<vector<bool>> &boxes, int r, int c)
{
    vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    for (int d = 0; d < dir.size(); d++)
    {
        for (int rad = 1; rad <= boxes.size(); rad++)
        {
            int x = r + rad * dir[d][0];
            int y = c + rad * dir[d][1];

            if (x >= 0 && y >= 0 && x < boxes.size() && y < boxes[0].size())
            {
                if (boxes[x][y])
                    return false;
            }
        }
    }
    return true;
}
int Nqueen_01(vector<vector<bool>> &boxes, int tnq, int idx, string ans) // tnq is equal to target.
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();
        if (isSafeToPlaceQueen(boxes, r, c))
        {
            boxes[r][c] = true;
            count += Nqueen_01(boxes, tnq - 1, i + 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
            boxes[r][c] = false;
        }
    }
    return count;
}
int main()
{
    int n = 4;
    int m = 4;

    vector<vector<bool>> boxes(n, vector<bool>(m, 0));
    int tnq = n;
    cout << Nqueen_01(boxes, tnq, 0, "") << endl;
    return 0;
}