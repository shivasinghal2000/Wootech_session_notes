#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
vector<string>dirs{"D","R","U","L"};
int floodfillsinglejump(int sr, int sc, int er, int ec, vector<vector<bool>>&board,string ans)
{
    if(sr==er && ec==sc)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    board[sr][sc]=1; // mark
    for(int i=0;i<dir.size();i++)
    {
        int r=sr+dir[i][0];
        int c=sc+dir[i][1];
        if (r >= 0 && r < board.size() && c >= 0 && c < board[0].size() && board[r][c]==0)
        {
            count += floodfillsinglejump(r,c,er,ec,board,ans + dirs[i] + " " ); // use
        }
    }
    board[sr][sc] = 0; //unmark
    return count;
}
int floodfillmultijump(int sr, int sc, int er, int ec, vector<vector<bool>> &board, string ans)
{
    if (sr == er && ec == sc)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    board[sr][sc] = 1; // mark
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < dir.size(); i++)
    {
        for(int jump_rad=1;jump_rad<max(n,m);jump_rad++)
        {
            int r = sr + jump_rad * dir[i][0];
            int c = sc + jump_rad * dir[i][1];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 0)
            {
                count += floodfillmultijump(r, c, er, ec, board, ans + dirs[i] + to_string(jump_rad) + " "); // use
            }
        }
        
    }
    board[sr][sc] = 0; //unmark
    return count;
}
class floodpair
{
    public:
    string str="";
    int len=0;
    floodpair(string s,int l)
    {
        str=s;
        len=l;
    }
};
floodpair longestpath(int sr, int sc, int er, int ec, vector<vector<bool>> &board, string ans)
{
    if (sr == er && ec == sc)
    {
        // cout << ans << endl;
        floodpair base("",0);
        return base;
    }
    int count = 0;
    board[sr][sc] = 1; // mark
    int n = board.size();
    int m = board[0].size();
    floodpair myans("", 0);
    for (int i = 0; i < dir.size(); i++)
    {
        for (int jump_rad = 1; jump_rad < max(n, m); jump_rad++)
        {
            int r = sr + jump_rad * dir[i][0];
            int c = sc + jump_rad * dir[i][1];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 0)
            {
                floodpair recans = longestpath(r, c, er, ec, board, ans + dirs[i] + to_string(jump_rad) + " "); // use
                if(myans.len < recans.len + 1)
                {
                    myans.len=recans.len+1;
                    myans.str = dirs[i] + to_string(jump_rad) + recans.str;
                }
            }
        }
    }
    board[sr][sc] = 0; //unmark
    return myans;
}
int main()
{
    int n,m;
    n=3,m=3;
    vector<vector<bool>>board(n,vector<bool>(m,0));
    // cout << "count = " << floodfillmultijump(0, 0, n - 1, m - 1, board, "") << endl;
    floodpair myans = longestpath(0, 0, n - 1, m - 1, board, "");
    cout<<myans.len<<endl;
    cout<<myans.str<<endl;
}