#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& A, vector<int>& B) 
{
        // basic approach
        int n=A.size();
        int m=B.size();
        int p1=0,p2=0;
        int count=0;
        double m1=0,m2=0;
        if((n+m)%2 ==0) //even number of elements
        {
            while(count<=(n+m)/2)
            {
                count++;
                m2=m1;
                if(p1<n && p2<m)
                {
                    if(A[p1]<B[p2])
                    {
                        m1=A[p1];
                        p1++;
                    }
                    else
                    {
                        m1=B[p2];
                        p2++;
                    }
                }
                else if(p1<n)
                {
                     m1=A[p1];
                     p1++;
                }
                else if(p2<m)
                {
                     m1=B[p2];
                     p2++;
                }
            }
            return (m1+m2)/2;
        }
        else // odd number of elements
        {
            while(count<=(n+m)/2)
            {
                count++;
                if(p1<n && p2<m)
                {
                    if(A[p1]<B[p2])
                    {
                        m1=A[p1];
                        p1++;
                    }
                    else
                    {
                        m1=B[p2];
                        p2++;
                    }
                }
                else if(p1<n)
                {
                     m1=A[p1];
                     p1++;
                }
                else if(p2<m)
                {
                     m1=B[p2];
                     p2++;
                }
            }
            return m1;
        }
}
int main()
{
    vector<int>A={1,2,3,4};
    vector<int>B={-1,-1,0,7};
    cout << findMedianSortedArrays(A,B)<<endl;
}