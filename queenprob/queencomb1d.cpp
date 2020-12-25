#include <bits/stdc++.h>
using namespace std;
int queenCombination_1D(vector<bool> &boxes, int tnq, int idx, int qpsf, string ans) // tnq is equal to target.
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < boxes.size(); i++)
    {
        count += queenCombination_1D(boxes, tnq, i + 1, qpsf + 1, ans + "b" + to_string(i) + "q" + to_string(qpsf) + " ");
    }
    return count;
}
int queenCombination_1D_subseq(vector<bool> &boxes, int tnq, int idx, int qpsf, string ans) // tnq is equal to target.
{
    if (qpsf == tnq || idx == boxes.size())
    {
        if (qpsf == tnq)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    count += queenCombination_1D_subseq(boxes, tnq, idx + 1, qpsf + 1, ans + "b" + to_string(idx) + "q" + to_string(qpsf) + " ");
    count += queenCombination_1D_subseq(boxes, tnq, idx + 1, qpsf, ans);

    return count;
}
void queenCombinationPermuation()
{
    vector<bool> boxes(5, false);
    int tnq = 3;
    cout << queenCombination_1D(boxes, tnq, 0, 0, "") << endl;
    cout << queenCombination_1D_subseq(boxes, tnq, 0, 0, "") << endl;
}
int main()
{
    queenCombinationPermuation();
     return 0;
}