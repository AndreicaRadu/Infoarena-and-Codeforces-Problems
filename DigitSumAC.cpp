#include<bits/stdc++.h>
using namespace std;
 
long long dp[100100][2][110];
 
int main()
{
    long long MOD = 1000000007;
    string K;
    int D;
    cin >> K >> D;
    int n = K.length();
 
    dp[0][0][0] = 1;
    for(int i=0 ; i<n ; i++)
    {
        int a = (int)K[i] - 48;
        for (int j=0 ; j<D ; j++)
        {
            for (int d=0 ; d<10 ; d++)
            {
                dp[i+1][1][(j+d)%D] += dp[i][1][j];
                dp[i+1][1][(j+d)%D] %= MOD;
            }
            for (int d=0 ; d<a ; d++)
            {
                dp[i+1][1][(j+d)%D] += dp[i][0][j];
                dp[i+1][1][(j+d)%D] %= MOD;
            }
            dp[i+1][0][(j+a)%D] += dp[i][0][j];
            dp[i+1][0][(j+a)%D] %=MOD;
        }
    }
    cout << (dp[n][1][0] + dp[n][0][0] - 1 + MOD) % MOD;
    return 0;
}
