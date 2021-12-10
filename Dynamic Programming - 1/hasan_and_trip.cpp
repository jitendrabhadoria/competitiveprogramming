// Hasan and Trip
// Send Feedback
// Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
// There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
// Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
// Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
// Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
// Input format:
// First line will contain T(number of test case).
// First line of each test case will contain an integer N 
// Next N lines of that test case will contain three space-separated integers Xi, Yi, Fi (coordinates and happiness)
// Output format:
// For each test Output one number rounded to 6 digits after floating point, the maximum possible happiness in newline, Hasan can get. 
// Note: If answer is 2 print 2.000000
// Constraints:
// 1 <= T <= 50
// 1 <= N <= 500
// 0 <= Xi, Yi, Fi <= 100,000
// Sample Input
// 1
// 3
// 0 0 1
// 3 1 1
// 6 0 9
// Sample Output
// 4.675445

#include<bits/stdc++.h>
using namespace std;


struct city{
    int X;
    int Y;
    int F;
};



int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;      
        vector<city> cities(n+10);
        for(int i=1;i<=n;i++){
            cin >> cities[i].X >> cities[i].Y >> cities[i].F;
        }
        
        
		double dp[3005];

        
        for(int i=0; i<3005; i++){
    		dp[i]=-1*1e9;
    	}
    	
    	dp[1]=cities[1].F;
    	
    	for(int i=1; i<=n; i++){
    		
    		for(int j=1; j<i; j++){
    			
    			
    			dp[i] = max(dp[i], 
                            dp[j]+cities[i].F-(sqrt(pow(cities[i].X-cities[j].X,2)
                                                    +
                                                    pow(cities[i].Y-cities[j].Y,2)
                                                   )
                                              )
                           );
    		
    		}
    		
    	}
        
        printf("%.6f",dp[n]);
        cout<<endl;
        
    
    }
    return 0;
}

// In my solution, dp[i] state represents the maximum happiness we can attain by ending our tour from city 1 to city i.
// Now, obviously dp[1], i.e the maximum happiness you can gain by starting your tour from city 1 and ending it at city 1 itself is going to be the F1. This stands as our base case.
// Now, I am using an iterative style DP. Suppose I have to fill dp[i], then I will check for each j ( 1<=j<i ), which city ( j ) to choose from 1 to i so that if I end my tour at city i, I will have the maximum magnitude of happiness. THIS IS IMPORTANT.
// Now for each i iterating through 1 to N, you will subsequently be solving dp[i], and if you focus you will find that the answer to the problem is nothing but dp[N]. Thats it!
// Now I’ve set each dp[i] except i=1 as -1e9 so that when I iterate through all the j’s ([1,i-1]) I wil have to choose the max of happiness possible at state i, because there is no way I’'ll have any smaller happiness than -1e9, so taking it as maximum initially before checking for all j will give me a result.
