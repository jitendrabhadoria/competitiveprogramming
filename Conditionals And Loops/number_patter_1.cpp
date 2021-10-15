/*

Print the following pattern
Pattern for N = 4
1
23
345
4567

Input Format :
N (Total no. of rows)

Output Format :
Pattern in N lines

Sample Input 1 :
3
Sample Output 1 :
1
23
345

*/
#include<iostream>
using namespace std;


int main(){
	int N;
    cin>>N;
    int i,j,k,l;
    i=1;
    while(i<=N){
        j=1;
        k=i;
        while(j<=i){
            cout<<k;
            k++;
            j++;
        }
        cout<<endl;
        i++;
    }
}


