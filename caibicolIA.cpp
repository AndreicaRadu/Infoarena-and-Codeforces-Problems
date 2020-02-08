#include <bits/stdc++.h>
using namespace std;
ifstream fin("caibicol.in"); ofstream fout("caibicol.out");
 
int main()
{
    int N , K , dp[1000][1000];
    fin >> N >> K;
    vector<int> n(N+2 , 0) , a(N+2 , 0);
    for(int i=1 ; i<=N ; i++)
    {
        int aux; fin >> aux;
        a[i] += a[i-1];
        n[i] += n[i-1];
        if(aux) n[i]++;
        else a[i]++;
        dp[1][i] = n[i] * a[i];
    }
    for(int i=2 ; i<=K ; i++)
        for(int j=1 ; j<=N ; j++)
        {
            dp[i][j] = INT_MAX;
            for(int l=1 ; l<=j ; l++)
                dp[i][j] = min(dp[i][j] , (a[j] - a[l-1]) * (n[j] - n[l-1]) + dp[i-1][l-1]);
        }
    fout << dp[K][N];
 
    return 0;
}
