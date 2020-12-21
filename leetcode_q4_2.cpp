#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> &X, vector<int> &Y)
{
    // optimized approach
    int x = X.size();
    int y = Y.size();
    //if A length is greater then switch them so that A is smaller than B
    if (x > y)
        return findMedianSortedArrays(Y, X);
    int start = 0, end = x; //two array hence don't use end=x-1 as smaller array may be empty
    while (start <= end)
    {
        int partitionX = (start + end) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;
        //if partitionX is 0 it means nothing is there on left side. Use -INF for minX

        //if partitionX is length of input then there is nothing on right side. Use +INF for maxX

        //update min and max which are left/right neighbouring values around partition
        int minX = (partitionX == 0) ? INT_MIN : X[partitionX - 1];
        int maxX = (partitionX == x) ? INT_MAX : X[partitionX];
        int minY = (partitionY == 0) ? INT_MIN : Y[partitionY - 1];
        int maxY = (partitionY == y) ? INT_MAX : Y[partitionY];

        if (minX <= maxY && minY <= maxX)
        {
            // we have partitioned at correct place
            if ((x + y) % 2 == 0)
            {
                // cout << max(minX, minY) << " " << min(maxX, maxY) << endl;
                return ((double)(max(minX, minY) + min(maxX, maxY)) / 2);
            }
            else
                return (double)(max(minX, minY));
        }
        else if (minX > maxY)
        {
            //we are too far on right side for partitionX. Go on left side.
            end = partitionX - 1;
        }
        else
        {
            //we are too far on left side for partitionX. Go on right side.
            start = partitionX + 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {-1, -1, 0, 7};
    cout << findMedianSortedArrays(A, B) << endl;
}