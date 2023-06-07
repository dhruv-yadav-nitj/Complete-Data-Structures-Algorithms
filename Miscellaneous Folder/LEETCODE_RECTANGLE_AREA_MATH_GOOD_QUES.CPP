
#include <bits/stdc++.h>
using namespace std;

// A good tricky maths and geometry question. Just remember one thing that two rectangles would overlap if the overlapping length and breadth is greater than 0. The main point is finding the coordinates of the overlapping rectangle.

class Solution
{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
    {
        // first we need to calculate the area of each rectangle and then calculate the common area and then subtract the common area from total area of both rectangles
        int len1, bre1, len2, bre2;
        len1 = (ax2 - ax1), bre1 = (ay2 - ay1);
        len2 = (bx2 - bx1), bre2 = (by2 - by1);
        int ar1, ar2;
        ar1 = len1 * bre1;
        ar2 = len2 * bre2;

        // so now we have the total area
        int total = ar1 + ar2;

        // now let us calculate the common area

        // we have been given two rectangles then these two rectangles would not overlap when either one of the rectangle lies above the top of other or to the left of the left edge.
        // let check

        // bool flag = false;
        // if(bx2 <= ax1 or bx1 >= ax2 or by2 <= ay1 or ay2 <= by1)
        // {
        //     flag = true;
        // }

        // if(!flag)return total;

        // calculating the overlapping area
        // length of overlapping area
        int lap_len = min(ax2, bx2) - max(ax1, bx1);
        int lap_bre = min(ay2, by2) - max(ay1, by1);

        int overlapAr = 0;

        if (lap_len > 0 and lap_bre > 0)
            overlapAr = lap_len * lap_bre;

        return (total - overlapAr);
    }
};