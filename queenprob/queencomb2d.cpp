#include <bits/stdc++.h>
using namespace std;
int queenCombination_2D(vector<vector<bool>> &boxes, int tnq, int idx, int qpsf, string ans) // tnq is equal to target.
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size() * boxes[0].size(); i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();
        count += queenCombination_2D(boxes, tnq, i + 1, qpsf + 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
    }
    return count;
}
void queenCombinationPermuation()
{
    vector<vector<bool>> boxes(4, vector<bool>(4, 0));
    int tnq = 4;
    cout << queenCombination_2D(boxes, tnq, 0, 0, "") << endl;
}