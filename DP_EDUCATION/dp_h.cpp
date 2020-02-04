#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
#define MO 1e9+7
#define LINF 1e18 + 5

using namespace std;
using ll = long long;
int h,w;
const ll mod = 1e9+7;
char s[1002][1002];
ll dp[1002][1002];

ll solve(int y, int x){
    if(s[y][x]=='#'||s[y][x]==0) return 0; //이건 삑사리 났을 때
    ll& res = dp[y][x];
    if(res!=-1) return res; //이미 계산했다면 리턴
    res = (solve(y+1,x) + solve(y,x+1))%mod;
    return res;
}

int main()
{
    cin>>h>>w;
    memset(dp, -1, sizeof(dp));
    dp[h][w]=1;
    for(int i=1;i<=h;i++){
        scanf("%s", s[i]+1);
    }
    cout<<solve(1,1);
    
    return 0;
}