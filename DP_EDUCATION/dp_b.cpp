#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
using namespace std;

int solve(int n, int k, vector<int> &c, vector<int> &dp)
{
    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];
    int best = INF;
    for(int i=1;i<=k;i++){
        if(n-i>0) best = min(best, solve(n-i,k,c,dp)+abs(c[n]-c[n-i]));
    }
    return dp[n] = best;
}

int main()
{
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    vector<int> c(n + 1);
    vector<int> dp(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
    }
    //재귀로 풀어봅시다.
    //solve 는 n일 때 최소가 되는 값을 반환하는 함수라고 합시다.
    dp[0] = INF;
    printf("%d", solve(n, k, c, dp));
    return 0;
}
