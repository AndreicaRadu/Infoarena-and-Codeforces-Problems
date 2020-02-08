#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("custi.in"); ofstream fout("custi.out");
 
int main()
{
    int m[1010] , dp[1010][1010] , n;
    fin >> n;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            fin >> dp[i][j];
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=n ; j++)
            if(dp[i][j])
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                m[dp[i][j]]++;
            }
    for (int i=n ; i>0 ; i--)
        m[i] += m[i + 1];
    for (int i=1 ; i<=n ; i++)
        fout << m[i] << "\n";
    return 0;
}
