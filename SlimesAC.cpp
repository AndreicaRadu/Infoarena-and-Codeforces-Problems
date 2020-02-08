#include <bits/stdc++.h>
using namespace std;
 
long long a[500][500] , dp[500][500] , slm[500];
int main()
{
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> slm[i];
 
    for(int i=0 ; i<n ; i++)
        for(int j=i ; j<n ; j++)
            for(int k=i ; k<=j ; k++)
                a[i][j] += slm[k];
 
    for(int i=0 ; i<n ; i++)
    {
        dp[i][i] = 0;
        for(int j=i+1 ; j<n ; j++)
            dp[i][j] = LLONG_MAX;
    }
    for(int i=n-1 ; i>=0 ; i--)
        for(int j=i+1 ; j<n ; j++)
            for(int k=i ; k<j ; k++)
                dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k+1][j] + a[i][j]);
    cout<<dp[0][n-1];
}
