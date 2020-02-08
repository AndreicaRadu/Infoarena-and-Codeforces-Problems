#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("dezastru.in"); ofstream fout("dezastru.out");
 
int main()
{
    int n , k;
    double v[30] , dp[30][30], fct[30];
    fin >> n >> k;
    for(int i=1 ; i<=n ; i++)
        fin >> v[i];
 
    fct[0] = 1;
    for(int i=1 ; i<=n ; i++)
    {
        fct[i] = fct[i-1] * i;
        dp[i][0]=1;
    }
    dp[0][0] = 1;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=i ; j++)
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] * v[i];
 
    fout << fixed << setprecision(10) << dp[n][k] * fct[k] * fct[n-k] / fct[n];
}
