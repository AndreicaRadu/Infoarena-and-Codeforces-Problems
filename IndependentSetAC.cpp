#include <bits/stdc++.h>
using namespace std;
vector <vector<int>> G;
long long f[100100] , dp[100100][2] , MOD = 1000000007; //0 alb 1 negru;
 
void dfs(int x)
{
    f[x] = 1;
    long long p0 = 1;
    long long p1 = 1;
    for (int y : G[x])
        if(!f[y])
        {
            dfs(y);
            (p0 *= (dp[y][0] + dp[y][1])) %= MOD;
            (p1 *= dp[y][0]) %= MOD;
        }
    dp[x][0] = p0 % MOD;
    dp[x][1] = p1 % MOD;
}
int main()
{
    int n;
    cin >> n;
    G.resize(n+1);
    for (int i=0 ; i<n-1 ; i++)
    {
        int x , y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1);
    cout << (dp[1][0] + dp[1][1]) % MOD;
 
    return 0;
}
