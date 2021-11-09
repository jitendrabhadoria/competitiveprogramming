// Second Largest in array
// Send Feedback
// You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.
// If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2 ^ 31(It is the smallest value for the range of Integer)
// Input format :
// The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

// The first line of each test case or query contains an integer 'N' representing the size of the array/list.

// The second line contains 'N' single space separated integers representing the elements in the array/list.
// Output Format :
// For each test case, print the second largest in the array/list if exists, -2147483648 otherwise.

// Output for every test case will be printed in a separate line.
// Constraints :
// 1 <= t <= 10^2
// 0 <= N <= 10^5

// Time Limit: 1 sec
// Sample Input 1:
// 1
// 7
// 2 13 4 1 3 6 28
// Sample Output 1:
// 13
// Sample Input 2:
// 1
// 5
// 9 3 6 2 9
// Sample Output 2:
// 6
// Sample Input 3:
// 2
// 2
// 6 6
// 4
// 90 8 90 5
// Sample Output 3:
// -2147483648
// 8


#include <iostream>
using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
 
 
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; 
    
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
 


int findSecondLargest(int *input, int n)
{
    bool same=true;
    int temp=input[0];
    int j=n-1,i;
    if(n<=1){
        return -2147483648;
    } else {
        for(int i=0;i<n;i++){
            if(input[i]!=temp){
                same=false;
                break;
            }
        }
        if(same){
            return -2147483648;
        } else {
            mergeSort(input, 0, n - 1);
           	temp=input[n-1];
            
            while(input[j--]==temp){
                //Eat Five Star
            }
            return input[j+1];
        }
    }
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}