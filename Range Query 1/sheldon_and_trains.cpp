// Sheldon and Trains
// Send Feedback
// Sheldon always tells people, “When you have only one day to visit Los Angeles, make it a Train Day”. He loves spending time while travelling in trains and considers it a fun activity. Sheldon’s mom has come to visit him and he decides to take her out on a train tour of the city of Pasadena, along with his friend Howard. There are n train stations in the city. Howard knows how irritating Sheldon can be during a train ride. So, to keep him busy, Howard gives Sheldon a problem so interesting that he just cannot do anything else other than devote his entire mind to solving it. The problem goes like this. At the i-th station it's possible to buy only tickets to stations from i + 1 to ai (inclusive). No tickets are sold at the last station.
// Let ρi, j be the minimum number of tickets one needs to buy in order to get from stations i to station j. Sheldon’s task is to compute the sum of all values ρi, j among all pairs 1 ≤ i < j ≤ n. As brilliant as he may be, he asked for your help.
// Input Format:
// First line of input will contain N number of trains 
// Second line will contain N-1 space-separated integers denoting the values of ai
// Output Format:
// Print the answer as mentioned above
// Constraints:
// 2 < = N <= 10^5
// i + 1 <=arr[i] <= N
// Sample Input 1:
// 7
// 2 7 5 7 6 7 
// Sample Output 1:
// 29

#include<bits/stdc++.h>
using namespace std;
#define MAXN 111111

struct Node{
    int mmm,idx;
    Node():mmm(0){}
}tree[MAXN<<2];
int x,y,N;
void update(int i,int j,int k){
    if(i==j){
        tree[k].mmm=y;
        tree[k].idx=i;
        return;
    }
    int mid=i+j>>1;
    if(x<=mid) update(i,mid,k<<1);
    else update(mid+1,j,k<<1|1);
    if(tree[k<<1].mmm>tree[k<<1|1].mmm){
        tree[k]=tree[k<<1];
    }else{
        tree[k]=tree[k<<1|1];
    }
}
Node query(int i,int j,int k){
    if(x<=i && j<=y){
        return tree[k];
    }
    int mid=i+j>>1;
    Node ret;
    if(x<=mid){
        Node tmp=query(i,mid,k<<1);
        if(ret.mmm<tmp.mmm) ret=tmp;
    }
    if(y>mid){
        Node tmp=query(mid+1,j,k<<1|1);
        if(ret.mmm<tmp.mmm) ret=tmp;
    }
    return ret;
}

int a[MAXN];
long long d[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    for(N=1; N<n; N<<=1);
    for(int i=1; i<n; ++i){
        scanf("%d",a+i);
        x=i; y=a[i];
        update(1,N,1);
    }
    x=n; y=n;
    update(1,N,1);
    for(int i=n-1; i>=1; --i){
        x=i+1; y=a[i];
        Node tmp=query(1,N,1);
        d[i]=d[tmp.idx]+n-i-(a[i]-tmp.idx);
    }
    long long res=0;
    for(int i=1; i<=n; ++i){
        res+=d[i];
    }
    printf("%lld",res);
    return 0;
}