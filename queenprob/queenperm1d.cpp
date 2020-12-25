#include <bits/stdc++.h>
using namespace std;
int queenPermutation_1D(vector<bool> &boxes, int tnq, int idx, int qpsf, string ans) // tnq is equal to target.
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size(); i++)
    {
        if (!boxes[i])
        {
            boxes[i] = true;
            count += queenPermutation_1D(boxes, tnq, 0, qpsf + 1, ans + "b" + to_string(i) + "q" + to_string(qpsf) + " ");
            boxes[i] = false;
        }
    }
    return count;
}
void queenCombinationPermuation()
{
    vector<bool> boxes(5, false);
    int tnq = 3;
    cout << queenPermutation_1D(boxes, tnq, 0, 0, "") << endl;
}