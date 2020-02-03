#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
using namespace std;
using ll = long long;
vector<ll> v;
vector<ll> w;
vector<vector<ll>> memo;
ll solve(ll n, ll k)
{
    if(n<0) return 0;
    ll best = -1;  
    if(memo[n][k]!=-1) return memo[n][k];
    if(k-w[n]>=0){
        best = max(best, solve(n-1,k-w[n])+v[n]);
    }
    best = max(best, solve(n-1,k));
    
    memo[n][k]=best;
    return best;
}

void max_self(ll& a, ll b){
    a = max(a,b);
}

int main(){//선형으로 풀어버린다!
    int n, W;
    scanf("%d%d",&n,&W);
    vector<ll> dp(W+1); //0...W까지 저장하자
    //dp[i]는 무게가 i일때 최대의 value를 출력한다.
    for(int item=0;item<n;item++){
        int weight, value;
        scanf("%d %d",&weight, &value);
        for(int weight_alredy=W-weight;weight_alredy>=0;weight_alredy--){
            max_self(dp[weight_alredy+weight], dp[weight_alredy]+value);
        }
    }
    ll ans = 0;
    for(int i =0;i<=W;i++){
        max_self(ans, dp[i]);
    }
    printf("%lld",ans);
    return 0;
} 

int main2() //재귀로 풀기..
{
    ll n, W;
    scanf("%lld %lld", &n, &W);
    v.resize(n + 1);
    w.resize(n + 1);
    memo.resize(n + 1, vector<ll>(W+1, -1));
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld %lld", &w[i], &v[i]);
    }
 
    //solve 는 n번째 물건이고 무게가 W일때..
    cout << solve(n, W);

 
    return 0;
}