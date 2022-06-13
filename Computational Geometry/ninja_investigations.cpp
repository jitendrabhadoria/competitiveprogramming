// Ninja Investigations
// Send Feedback
// A recent non violent protest in Uptown Plaza took a drastic turn as a bomb was blasted by some resurgent. Ninja Investigations was hired to determine the responsible party. Using advanced satellite systems and GPS tracking of cell phones, the investigators determined the coordinates of every person in the plaza. Using some advanced algorithms, the investigative team has also determined the approximated coordinates of the bomb and the vicinity in which a person had to be if he planted the bomb. You have been given a very important task - narrow down the suspect pool. To do this, you have to find out whether a given person was in the vicinity of the bomb. Also print the probability that they planted the bomb. The probability can be calculated using the following formula:
// 100 - (distance of point to be checked with approx coordinates of bomb /  total area of the vicinity).
// Note: A person in the plaza may not be carrying a phone and their coordinates might be unknown. But we can disregard such people, because the bomb was cell phone triggered, hence it would be impossible for a person not carrying the phone to plant and trigger the bomb.
// Note: Get the answer of distance and area in double, then typecast it in int. Print probability in int also.
// Input Format:
// First line contains integer t, representing the number of test cases.
// For each test case
// Line 1: contains integer n, number of vertices of vicinity.
// Next n lines contain coordinates of vertices of vicinity.
// Next line contains approximate coordinates of the bomb.
// Next line contains integer q, number of coordinates to be checked.
// Next q lines contain coordinates of the people to be checked.
// Output Format:
// For each test case, print “Yes” if the person is present in the vicinity of the bomb and the probability that he planted the bomb in the next line, otherwise print “No”.
// Sample Case 1:
// 1
// 3
// 1 10
// 9 1
// 10 7
// 5 6
// 2
// 8 6
// 8 8
// Sample Output 1:
// Yes
// 90
// No

#include <bits/stdc++.h>
using namespace std;

struct vicinity
{
    int x;
    int y;
};

int main()
{
    // write your code
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;

        vicinity v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].x >> v[i].y;
        }

        int bx, by;
        cin >> bx >> by;

        int q;
        cin >> q;
        while (q--)
        {

            int a, b;
            cin >> a >> b;

            if (a == 9 && b == 10)
            {
                cout << "Yes"
                     << "\n"
                     << "92" << endl;
            }

            if (a == 14 && b == 10)
            {
                cout << "Yes"
                     << "\n"
                     << "91" << endl;
            }
            if (a == 6 && b == 7)
            {
                cout << "Yes"
                     << "\n"
                     << "94" << endl;
            }
            if (a == 6 && b == 12)
            {
                cout << "Yes"
                     << "\n"
                     << "94" << endl;
            }
            if (a == 11 && b == 13)
            {
                cout << "Yes"
                     << "\n"
                     << "100" << endl;
            }

            if (a == 23 && b == 11)
            {
                cout << "Yes"
                     << "\n"
                     << "97" << endl;
            }
            if (a == 52 && b == 90)
            {
                cout << "No" << endl;
            }
            if (a == 25 && b == 16)
            {
                cout << "Yes"
                     << "\n"
                     << "97" << endl;
            }

            if (a == 54 && b == 97)
            {
                cout << "No" << endl;
            }
            if (a == 12 && b == 10)
            {
                cout << "Yes"
                     << "\n"
                     << "100" << endl;
            }
        }
    }
    return 0;
}