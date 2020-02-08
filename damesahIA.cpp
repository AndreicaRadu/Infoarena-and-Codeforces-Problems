#include<bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("damesah.in"); ofstream fout("damesah.out");
 
int n , uz[16] , ans[16] , dp[32] , ds[32] , nr=0;
void bt(int k)
{
    if(k > n)
    {
        nr++;
        if(nr == 1)
            for(int i = 1; i <= n; i++)
                fout << ans[i] << " ";
    }
    for(int i=1 ; i<=n ; i++)
    {
        if(!uz[i] && !dp[k-i+n] && !ds[i+k])
        {
            uz[i] = 1; dp[k-i+n] = 1; ds[i+k] = 1;
            ans[k] = i;
            bt(k+1);
            uz[i] = 0; dp[k-i+n] = 0; ds[i+k] = 0;
        }
    }
}
int main()
{
    fin >> n;
    bt(1);
    fout << "\n" << nr;
    return 0;
}
