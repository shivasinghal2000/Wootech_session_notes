#include <bits/stdc++.h>
using namespace std;
vector<bool> rowA;   // n   
vector<bool> colA;   // m
vector<bool> diagA;  // n+m-1
vector<bool> adiagA; //n+m-1


int calls = 0;

int Nqueen_04(int n, int m, int tnq, int r, string ans) // tnq is equal to target.
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    calls++;

    for (int c = 0; c < m; c++)
    {
        if (!rowA[r] && !colA[c] && !diagA[r + c] && !adiagA[r - c + m - 1])
        {
            rowA[r] = true;
            colA[c] = true;
            diagA[r + c] = true;
            adiagA[r - c + m - 1] = true;

            count += Nqueen_04(n, m, tnq - 1, r + 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");

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
    cout << Nqueen_04(n, m, tnq, 0, "") << endl;

    cout << calls << endl;
}

int main()
{
    Nqueen();
    return 0;
}