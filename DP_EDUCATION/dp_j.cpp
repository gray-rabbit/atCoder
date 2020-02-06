#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
#define MO 1e9 + 7
#define LINF 1e18 + 5
#define rep(i, N) for (int i = 0; i < N; i++)
#define repp(i, N) for (int i = 1; i <= N; i++)
using namespace std;
using ll = long long;

int n;
double dp[302][302][302];
bool chk[302][302][302];
int sushi[4];

double solve(int a, int b, int c)
{
    if (a == 0 && b == 0 && c == 0)
        return 0.0;
    if (chk[a][b][c])
        return dp[a][b][c];
    double res = 0.0;
    //아무것도 없는 접시를 선택하는 경우를 생각한다.
    res += (n - a - b - c) * 1.0 / (a + b + c) * 1.0;
    //1개 있는 접시를 선택하는 경우를 생각하자.
    if (a > 0)
        res += (solve(a - 1, b, c) + 1) * a / (a + b + c) * 1.0;
    //2개 있는 접시를 선택하는 경우를 생각하자.
    if (b > 0)
        res += (solve(a + 1, b - 1, c) + 1) * b / (a + b + c) * 1.0;
    //3개 있는 접시를 선택하는 경우를 생각하자.
    if (c > 0)
        res += (solve(a, b + 1, c - 1) + 1) * c / (a + b + c) * 1.0;
    chk[a][b][c] = 1;
    return dp[a][b][c] = res;
}

int main()
{
    cin >> n;
    rep(i, n)
    {
        int t;
        scanf("%d", &t);
        sushi[t]++;
    }
    dp[0][0][0] = 1.0;
    printf("%.10f", solve(sushi[1], sushi[2], sushi[3]));
    return 0;
}