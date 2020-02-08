#include <bits/stdc++.h>
using namespace std;
 
long long dp[101][100001] , w[101] , v[101];
int main()
{
    long long n , c , sum=0;
    cin >> n >> c;
    for(int i=1 ; i<=n ; i++)
    {
        cin >> w[i] >> v[i];
        sum+=v[i];
    }
    for(int i=0 ; i<=n ; i++)
        for(int j=0 ; j<=sum ; j++)
            dp[i][j] = c+1;
    dp[0][0] = 0;
    for(int i=1 ; i<=n ; i++)
        for(int j=0 ; j<=sum ; j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=v[i])
                dp[i][j] = min(dp[i][j] , dp[i-1][j-v[i]] + w[i]);
        }
    for(int i=sum ; i>=0 ; i--)
        if(dp[n][i]<=c)
        {
            cout << i;
            return 0;
        }
    printf("0");
    return 0;
}
