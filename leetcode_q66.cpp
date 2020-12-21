#include <bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size() - 1;
    vector<int> ans(digits);
    int carry = 1;
    for (int i = n; i >= 0; i--)
    {
        if (digits[i] + carry > 9)
        {
            ans[i] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        else
        {
            ans[i] = digits[i] + carry;
            carry = 0;
            break;
        }
    }
    if (carry == 1)
        ans.insert(ans.begin(), 1);
    return ans;
}
int main()
{
    vector<int> A = {1, 2, 3, 4};
    vector<int>B = plusOne(A);
    for(int i=0;i<B.size();i++)
    cout<<B[i]<<" ";
    cout<<endl;
}