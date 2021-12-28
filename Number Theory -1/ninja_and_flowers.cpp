// Ninja and Flowers
// Send Feedback
// Ninja wants to get N flowers and he will pay i + 1 amount of money for the Ith flower, example (if n=3 he will pay {2,3,4})
// Now he wants to pack these N flowers in boxes of different colours. With one condition if the cost of a flower is a prime divisor of another flower they needed to be of a different colour.
// As we know that ninja is a little money minded he wants to minimize the number of different colours of boxes that he needs.
// Input Format:
// The only line of input will contain an integer N (number of flowers).
// Output Format:
// In first-line print K, the minimum number of different colour boxes that are needed to pack the flowers.
// Next line contains K space-separated integers in sorted order denoting the counts of the different coloured boxes.
// Constraints:
// 1 <= N <= 2*10^5
// Sample Input:
// 4
// Sample Output:
// 2
// 1 3

#include<iostream>
using namespace std;

int makeSieve(int n){
    bool isPrime[n+1];
    for(int i=0;i<=n;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i=2;i*i<=n;i++){
        if(isPrime[i] == true){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for(int i=1;i<=n;i++){
        if(isPrime[i] == true){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    int nPrimes = makeSieve(n+1);
    int rem =  n-nPrimes;
 
    if(rem>nPrimes){
        cout<<2<<endl;
        cout<<nPrimes<<" "<<rem<<endl;
    } else {
        cout<<2<<endl;
        cout<<rem<<" "<<nPrimes<<endl;
    }
    
    return 0;
}
