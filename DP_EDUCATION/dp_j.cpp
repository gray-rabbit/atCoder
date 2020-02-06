#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
#define MO 1e9+7
#define LINF 1e18 + 5
#define rep(i, N) for(int i=0;i<N;i++)
#define repp(i,N) for(int i=1;i<=N;i++)
using namespace std;
using ll = long long;

int n;
double dp[3001][3001];
bool chk[3001][3001];
double coins[3000];
double solve(int y, int x){
    if(x<0) return 0.0;
    if(y==0) return dp[y][x];//이게 기저사례
    if(y<x) return 0.0;
    //y번째 동전까지 던졌을 때, x개의 헤드가 나오는 것을 반환한다?
    double& res = dp[y][x];
    if(chk[y][x]) return dp[y][x];
    
    res = solve(y-1,x-1)*coins[y]+ solve(y-1,x)*(1-coins[y]);
    chk[y][x]=1;
    return res;
}
int main(){
    cin>>n;
    //memset(dp, -1.0, sizeof(dp));
    for(int i =1;i<=n;i++){
        scanf("%lf", coins+i);
    }
    dp[0][0] = 1.0;
    double ans =0.0;
    for(int j=0;j<=n;j++){
        solve(n,j);
    }
    for(int j=0;j<=n;j++){
        if(j>n-j) ans += dp[n][j];
    }
    printf("%.15f\n",ans);

    return 0;
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=i;j++){
    //         if(j-1>=0){
    //             dp[i][j] += dp[i-1][j-1]*coins[i];
    //         }
    //         dp[i][j] += dp[i-1][j] * (1-coins[i]);
    //     }
    // }
    // double ans = 0.0;
    // for(int i =0;i<=n;i++){
    //     if(i>n-i) ans += dp[n][i];
    // }
    // cout<<ans;
    //solve(n,n);
    //cout<<dp[3][2];
    return 0;
}