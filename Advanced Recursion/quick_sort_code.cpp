// Quick Sort Code
// Send Feedback
// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.


// Input format :
// First line will contain T number of test case and each tet case will consist of two lines.
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// for every test case print rray elements in increasing order (separated by space) in a new line.
// Constraints :
// 1 <= T <= 10
// 1 <= n <= 10^5
// 0 <= arr[i] <= 10^9
// Sample Input 1 :
// 1
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 1
// 5
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 

#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0 ; i<n ; i++){
            cin>>a[i];
        }
        quickSort(a, 0, n - 1);
		for (int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}

