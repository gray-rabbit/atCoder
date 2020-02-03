#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
#define LINF 1e18 + 5

using namespace std;
using ll = long long;
vector<ll> v;
vector<ll> w;
vector<vector<ll>> memo;

//이 문제에서는 똑같은 백팩 문제인데.. W가 너무 크다. 10^9
//따라서 모든 v에 대한 값을 구하기로 해보자.
ll solve(int n, int k)
{
    if (n < 0)
        return 0;
    ll best = LINF;
    if (memo[n][k] != LINF)
        return memo[n][k];
    if (k - v[n] >= 0)
    {
        best = max(best, solve(n - 1, k - w[n]) + v[n]);
    }
    best = max(best, solve(n - 1, k));

    memo[n][k] = best;
    return best;
}

int main2() //이건 재귀로 어떻게 풀어야할지 모르겠네..;;
{
    int n, W;
    scanf("%d %d", &n, &W);
    v.resize(n + 1);
    w.resize(n + 1);
    int vsum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
        vsum += v[i];
    }
    memo.resize(n + 1, vector<ll>(vsum + 1, LINF));

    //solve 는 n번째 물건이고 모든 물건의 가치의 합은 vsum이라고 할때..
    cout << solve(n, vsum);

    return 0;
}
void min_self(ll &a, ll b)
{
    a = min(a, b);
}

int main()
{ //이건 선형으로 푼다.
    int n, W;
    cin >> n >> W;
    //dp[i] i 가 value때 최소의 weight를 구하자.
    v.resize(n + 1);
    w.resize(n + 1);
    int vsum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &v[i]);
        vsum += v[i];
    }
    vector<ll> dp(vsum + 1, LINF);
    dp[0]=0;
    for (int item = 0; item < n; item++)
    {
        for (int value_already = vsum - v[item]; value_already >= 0; value_already--)
        {
            min_self(dp[value_already+v[item]], dp[value_already]+ w[item]);
        }
    }
    ll ans = 0;
    for(int i=0;i<=vsum;i++){
        if(dp[i]<=W)
            ans = max(ans, (ll) i);
    }
    cout<<ans;
    return 0;
}