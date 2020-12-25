#include <bits/stdc++.h>
using namespace std;
vector<bool> rowA;   // n   Java: boolean[] rowA;
vector<bool> colA;   // m
vector<bool> diagA;  // n+m-1
vector<bool> adiagA; //n+m-1

int calls = 0;

int Nqueen_03(vector<vector<bool>> &boxes, int tnq, int idx, string ans) // tnq is equal to target.
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    calls++;

    int n = boxes.size();
    int m = boxes[0].size();
    for (int i = idx; i < n * m; i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();
        if (!rowA[r] && !colA[c] && !diagA[r + c] && !adiagA[r - c + m - 1])
        {
            rowA[r] = true;
            colA[c] = true;
            diagA[r + c] = true;
            adiagA[r - c + m - 1] = true;

            count += Nqueen_03(boxes, tnq - 1, i + 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");

            rowA[r] = false;
            colA[c] = false;
            diagA[r + c] = false;
            adiagA[r - c + m - 1] = false;
        }
    }
    return count;
}
void Nqueen()
{
    int n = 10;
    int m = 10;

    vector<vector<bool>> boxes(n, vector<bool>(m, 0));
    int tnq = n;

    rowA.resize(n, false);
    colA.resize(m, false);
    diagA.resize(n + m - 1, false);
    adiagA.resize(n + m - 1, false);

    cout << Nqueen_03(boxes, tnq, 0, "") << endl;

    cout << calls << endl;
}

int main()
{
    Nqueen();
    return 0;
}
//724
// 7534645
