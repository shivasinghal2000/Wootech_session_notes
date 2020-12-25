#include <bits/stdc++.h>
using namespace std;

//USING BITS MANIPULATION

int calls = 0;
int row = 0;
int col = 0;
int diag = 0;
int adiag = 0;

int Nqueen_05(int n, int m, int tnq, int r, string ans) // tnq is equal to target.
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
        if ((row & (1 << r)) == 0 && (col & (1 << c)) == 0 && (diag & (1 << (r + c))) == 0 && (adiag & (1 << (r - c + m - 1))) == 0)
        {
            row ^= (1 << r);
            col ^= (1 << c);
            diag ^= (1 << (r + c));
            adiag ^= (1 << (r - c + m - 1));

            count += Nqueen_05(n, m, tnq - 1, r + 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");

            row ^= (1 << r); 
            col ^= (1 << c);
            diag ^= (1 << (r + c));
            adiag ^= (1 << (r - c + m - 1));
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
    cout << Nqueen_05(n, m, tnq, 0, "") << endl;

    cout << calls << endl;
}

int main()
{
    Nqueen();
    return 0;
}