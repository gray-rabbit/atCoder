#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
#define LINF 1e18 + 5

using namespace std;
using ll = long long;
int n,m;
vector<vector<int>> path;
vector<int> dp;
int solve(int idx){
    if(dp[idx]!=-1) return dp[idx];//이미 방문했다면 리턴
    int& res = dp[idx];
    res = 0;// 방문 했다.
    for(auto k:path[idx]){
        res = max(res, solve(k) + 1);
    }
    return res;
}

int main()
{
    cin>>n>>m;
    path.resize(n+1);
    dp.resize(n+1,-1);
    int x,y;
    while(m--){
        cin>>x>>y;
        path[x].push_back(y);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,solve(i));
    }
    cout<<ans;



    
    return 0;
}