#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
using namespace std;
vector<vector<int>> v;
vector<vector<int>> memo;
int solve(int n, int k)
{
    if(n==-1) return 0;
    //기저사례만들기
    //처리하기
    if(memo[n][k]!=-1) return memo[n][k];
    int best = -1;
    for (int i = 1; i <= 3; i++)
    {
        
        if (k != i)
        {
            best = max(best, solve(n - 1, i) + v[n][k]);
        }
    }
    memo[n][k]=best;
    return best;
}

int main()
{
    int n, k;
    scanf("%d", &n);
    v.resize(n + 1, vector<int>(4));
    memo.resize(n + 1, vector<int>(4, -1));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i][1]);
        scanf("%d", &v[i][2]);
        scanf("%d", &v[i][3]);
    }

    //solve 는 n일때..
    cout<<solve(n, 0);

    return 0;
}
