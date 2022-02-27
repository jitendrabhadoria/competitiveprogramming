// Palindromic Substrings
// Send Feedback
// Given a string S, count and return the number of substrings of S that are a palindrome.
// Single length substrings are also palindromes. You just need to print the count of palindromic substrings, not the actual substrings.
// Input Format:
// First line of input contains an integer T, representing the number of test cases.
// Next T lines contain the string S
// Constraints :
// 1 <= Length of S <= 2000
// Output Format :
// For each test case, print the count of palindrome substrings in a new line.
// Sample Input 1:
// 1
// aba
// Sample Output 1:
// 4
// Explanation:
// The 4 palindrome substrings are "a", "b", "a" and "aba".

#include <bits/stdc++.h>
using namespace std;

int size(char s[])
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
int countPalindromeSubstrings(string s)
{
    int count = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        // odd length
        int left = i;
        int right = i;
        while (right < n && left >= 0 && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        // even length
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
    }
    return count;
}
int main()
{

    // write your code here
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;

        cout << countPalindromeSubstrings(s) << endl;
    }
    return 0;
}