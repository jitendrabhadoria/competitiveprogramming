// Maximum Sum Rectangle
// Send Feedback
// Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
// Input Format:
// First line of input will contain T(number of test case), each test case follows as.
// First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
// Output Format:
// Output a single integer, maximum sum rectangle for each test case in a newline.
// Constraints
// 1 <= T <= 50
// 1<=n,m<=100
// -10^5 <= mat[i][j] <= 10^5
// Sample Input
// 1
// 4 5
// 1 2 -1 -4 -20
// -8 -3 4 2 1
// 3 8 10 1 3
// -4 -1 1 7 -6
// Sample Output
// 29

#include <bits/stdc++.h>
using namespace std;

int kadane(int* arr, int* start, int* finish, int n)
{

	int sum = 0, maxSum = INT_MIN, i;

	*finish = -1;

	int local_start = 0;

	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*finish = i;
		}
	}

	if (*finish != -1)
		return maxSum;

	maxSum = arr[0];
	*start = *finish = 0;

	for (i = 1; i < n; i++)
	{
		if (arr[i] > maxSum)
		{
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}

void findMaxSum(int** M, int COL, int ROW)
{
	int maxSum = INT_MIN;

	int left, right, i;
	int temp[ROW], sum, start, finish;

	for (left = 0; left < COL; ++left) {
        
		memset(temp, 0, sizeof(temp));

		for (right = left; right < COL; ++right) {

			for (i = 0; i < ROW; ++i)
				temp[i] += M[i][right];

			sum = kadane(temp, &start, &finish, ROW);

		
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}

	cout <<maxSum<< endl;
}

int main(){
    
    
    int t;
    cin>>t;
    while(t--){
        
        int n,m;
        cin>>n>>m;
        int** M = new int* [n];
        for(int i=0;i<n;i++){
            M[i]=new int[m];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>M[i][j];
            }
        }
        findMaxSum(M,m,n);
    
    }
	return 0;
}
