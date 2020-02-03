#include <bits/stdc++.h>
#define N 100
#define INF 1e9 + 5
#define LINF 1e18 + 5

using namespace std;
using ll = long long;
string a, b;
int memo[3002][3002];
int solve(int y, int x)
{

    if (x == 0 || y == 0)
        return memo[y][x] = 0;
    int &best = memo[y][x];
    if (best != -1)
        return best;
    best = max(solve(y - 1, x), solve(y, x - 1));
    if (a[y] == b[x])
        best = max(best, solve(y - 1, x - 1) + 1);
    return best;
}
/*
 abyxb
a10000 
x11122
y11222
b12223
*/
int main()
{
    //std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b;
    a = "$" + a;
    b = "$" + b;
    int y , x;
    y = a.length()-1;
    x = b.length()-1;
    //memo.resize(a.length() + 1, vector<int>(b.length() + 1, -1));
    memset(memo, -1, sizeof(memo));
    int maxlenth = solve(y, x);
    string t = "";
    while (x > 0 && y > 0)
    {
        if (memo[y][x] == memo[y - 1][x])
            y--;
        else if (memo[y][x] == memo[y][x - 1])
            x--;
        else
        {
            t = a[y--] + t;
            x--;
        }
    }
    cout << t;
    return 0;
}