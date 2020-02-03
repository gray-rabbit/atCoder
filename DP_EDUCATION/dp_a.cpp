#include <iostream>
#include <bits/c++io.h>
#include <vector>
#include <tuple>
#include <queue>
#define N 100
#define INF 1e9 + 5
using namespace std;
 
int solve(int k, vector<int> &c,vector<int> &dp){
    if(k==1)return 0;
    if(k<1)return INF;
    if(dp[k]!=-1) return dp[k];
    return dp[k] = min( solve(k-1,c,dp)+abs(c[k]-c[k-1]), solve(k-2,c,dp)+abs(c[k]-c[k-2]));
}
 
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> c(n+1);
    vector<int> dp(n+1,-1);
    for (int i=1;i<=n;i++){
        scanf("%d", &c[i]);
    }
    //재귀로 풀어봅시다. 
    //solve 는 n일 때 최소가 되는 값을 반환하는 함수라고 합시다. 
    dp[0]=INF;
    printf("%d",solve(n, c, dp));
    //선형으로 풀어봅시다.
    // dp[0]=0; 
    // for(int i =0;i<n;i++){
    //     for(auto j:{i+1,i+2}){
    //         dp[j] = min( dp[j], dp[i]+abs(v[j]-v[i]) );
    //     }
    // }
    // cout<<dp[n-1];
 
    return 0;
}