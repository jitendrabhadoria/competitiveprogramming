// Red Riding Hood's Adventure
// Send Feedback
// Little Red Riding Hood has to go to her grandmother’s house. Her grandmother is very sick. To reach her house, Red Riding Hood has to cross a very long dark forest. She is also carrying a basket full of food for her journey. The forest was much longer than anticipated, and Riding Hood decided to take rest. She finds a cave and lights a campfire inside it to keep herself warm for the night. But alas! The campfire attracts the Big Bad Wolf.
// Luckily the Big Bad Wolf has recently turned vegetarian, and will not eat Red Riding Hood. He takes all the food that she was carrying instead, but decided to keep her as a minion. She cries a lot and begs the wolf to let her go. Big Bad Wolf used to be a problem solver in the past, and decides to let her go if and only if she is able to solve a problem for him. He gives the Red Riding Hood a long sentence “X” and a small word “W” . She has to find how many times word “W” occurs as a substring of “X” (spaces in the sentence are not to be considered). Red Riding Hood is just a kid, you have to help her solve the problem and escape the Big Bad Wolf.
// Input Format :
// First line of input will contain T(number of test cases). Each test case follows.
// Line 1: contains the sentence X
// Line 2: contains the string W
// Constraints:
// 1 <= T <= 100
// 1 <= |S| ,|s| <= 10^5
// Output Format:
// For each test case print the answer in a new line.
// Sample Input 1:
// 4
// axb ycz d
// abc
// ab  cab cabc abc
// abc
// aab acbaa bbaaz
// aab
// aaaaaa
// aa
// Sample Output 1:
// 0
// 4
// 2
// 5

#include <bits/stdc++.h>
using namespace std;

#define MAXN 100001

void computeLPSArray(string pat, int M,
                     int lps[])
{

    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = len;
                i++;
            }
        }
    }
}

int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();

    int lps[M];
    int j = 0;

    computeLPSArray(pat, M, lps);

    int i = 0;
    int res = 0;
    int next_i = 0;

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            j = lps[j - 1];
            res++;
        }

        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}

int main()
{

    // write your code here
    int t;
    cin >> t;
    cin.clear();

    while (t--)
    {

        cin.ignore();

        char X[MAXN];
        string W;

        string X2;
        string W2;

        cin.getline(X, MAXN);
        cin >> W;

        int j = 0;
        for (int i = 0; X[i] != '\0'; i++)
        {
            if (X[i] != ' ')
                X2 += X[i];
            else
                continue;
        }
        X2 += '\0';

        int ans = KMPSearch(W, X2);

        cout << ans << endl;
    }
    return 0;
}