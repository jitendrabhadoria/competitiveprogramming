/*

Print the following pattern
Pattern for N = 4
...*
..***
.*****
*******
The dots represent spaces.

Input Format :
N (Total no. of rows)

Output Format :
Pattern in N lines

Constraints :
0 <= N <= 50

Sample Input 1 :
3
Sample Output 1 :
   *
  ***
*******

Sample Input 2 :
4
Sample Output 2 :
    *
   *** 
  *****
 *******

*/

#include<iostream>
using namespace std;


int main(){
	int N;
    cin>>N;
    int i,j,k,l,m;
    i=1;
    m=0;
    while(i<=N){
        j=1;
        k=i;
        l=1;
        while(l<=(N-i)){
            cout<<" ";
            l++;
        }
        while(j<=i+m){
            cout<<"*";
            k++;
            j++;
        }
        cout<<endl;
        i++;
        m++;
    }
}


