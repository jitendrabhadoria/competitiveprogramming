// Red Scrabble
// Send Feedback
// Raymond “Red” Reddington is an international criminal hunted by the police forces of many countries. Recently, a joint Task Force, with the sole purpose of capturing Reddington, is launched, led by Agent Donald Ressler.
// Red has managed to elude all the forces because he is always one step ahead. Before Ressler can catch him, Red manages to capture Ressler for interrogation.
// Red is a huge fan of the game scrabble, and has created many modified versions of the game. He will let Ressler go, if he is able to solve one such version of the game.
// The premise is quite simple. Ressler is given a string S which contains only digits. He needs to count the number of substrings of S, which are palindromes. There are some additional rules to be followed. Red explains them as follows -
// Ressler needs to count the number of substrings of S, which are palindromes without leading zeros and can be divided by 3 without a remainder.
// A string is a palindrome without leading zeros if it reads the same backward as forward and doesn't start with the symbol '0'.
// Ressler should consider string "0" as a palindrome without leading zeros.
// You need to help Agent Ressler.
// Input Format:
// The first and only line of input contains string S.
// Constraints:
// 1 <= |S| <= 10^5
// 0 <= S[i] <= 9
// Output Format:
// Print the answer obtained.
// Sample Input 1:
// 10686
// Sample Output 1:
// 3
// Explanation:
// The three palindromic substrings are: 0, 6, 6.

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int cnt[2000005][3];
int sum[2000005];
string s;
ll answer = 0;

string daniTrick(string s)
{
    string dani = "";
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        dani += '@';
        dani += s[i];
    }
    return dani + '@';
}

int cal(int l, int r, int y)
{
    if (l > r)
        return 0;
    if (l > 0)
    {
        int total = (sum[l - 1] + y) % 3;
        return cnt[r][total] - cnt[l - 1][total];
    }
    return cnt[r][y];
}

void prepare(string s)
{
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < s.length(); ++i)
    {
        sum[i] = sum[i - 1];
        if (s[i] != '@')
        {
            sum[i] += (s[i] - '0');
            sum[i] %= 3;
        }
        for (int j = 0; j < 3; ++j)
        {
            cnt[i][j] = cnt[i - 1][j];
        }
        if (s[i] != '@' && s[i] != '0')
            cnt[i][sum[i]]++;
    }
}

int main()
{

    cin >> s;
    s = daniTrick(s);
    int n = s.length();
    vector<int> dp(n, 0);
    prepare(s);

    int l = 0, r = -1;

    for (int i = 0; i < n; ++i)
    {
        int k;
        if (i > r)
            k = 1;
        else
            k = min(r - i, dp[r - i + l]);
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
            k++;
        k--;
        dp[i] = k;
        if (i + k > r)
        {
            r = i + k;
            l = i - k;
        }
        if (s[i] != '@')
        {
            answer += cal(i + 1, i + k, (s[i] - '0') % 3);
            if ((s[i] - '0') % 3 == 0)
                ++answer;
        }
        else
        {
            answer += cal(i + 1, i + k, 0);
        }
    }
    cout << answer << endl;

    return 0;
}