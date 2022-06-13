// Area Of Convex Polygon
// Send Feedback
// A convex polygon is a set of n vertices that are joined by n edges, such that no two edges intersect and all angles are less than 180 degrees. We can represent a polygon by listing all the vertices, starting at one vertex and following the edges until that vertex is reached again. Thus, element 0 in the array represents the first vertex. The first vertex is connected to the second vertex (element 1), the second vertex is connected to the third vertex (element 2) and so on. The last element represents the last vertex, which is connected to the first vertex.
// Given the vertices of a polygon, return its exact area.
// Note: Get the integer part of the area. (It can be long). So get your answer in double, and typecast it into long.
// Input Format:
// First line of input will contain T(number of test cases), each test case follows.
// Line 1: Integer N denoting the number of points.
// Next N lines will denote the N cordinates (x,y) in a anticlockwise order.
// Constraints:
// 1 <= T <= 10^5
// 1 <= N <= 50
// 1 <= X <= Y <= 10^5
// The given polygon is guranted to be convex.
// Output Format:
// For each test case, print the area of polygon in new line.
// Sample Input 1:
// 1
// 4
// 1 5
// 2 2
// 9 2
// 7 5
// Sample Output 1:
// 19

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
class point
{
public:
    double x, y;
};
class polygon
{
public:
    point *points;
    polygon(int number_of_points)
    {
        points = new point[number_of_points];
    }
};
double area(polygon p, int n)
{
    double total_area = 0;
    for (int i = 1; i < n - 1; i++)
    {
        double x1 = p.points[i].x - p.points[0].x;
        double y1 = p.points[i].y - p.points[0].y;
        double x2 = p.points[i + 1].x - p.points[0].x;
        double y2 = p.points[i + 1].y - p.points[0].y;
        double cross_product = x1 * y2 - y1 * x2;
        total_area += cross_product;
    }
    return abs(total_area / 2);
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        polygon p(n);
        for (int i = 0; i < n; i++)
        {
            int xx, yy;
            cin >> xx >> yy;
            p.points[i].x = xx;
            p.points[i].y = yy;
        }
        // area
        cout << (int)area(p, n) << endl;
    }
    return 0;
}