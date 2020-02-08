#include<bits/stdc++.h>
using namespace std;
 
long long N, W;
long long ans[110][100100];
long long w[110], v[110];
 
int main()
{
    cin >> N >> W;
    for(int i=0 ; i<N ; i++)
        cin >> w[i] >> v[i];
    for(int i=0 ; i<N ; i++)
        for(long long j=0 ; j<=W ; j++)
        {
            if(j - w[i] >= 0)
                ans[i + 1][j] = max(ans[i][j - w[i]] + v[i] , ans[i + 1][j]);
 
            ans[i + 1][j] = max(ans[i + 1][j] , ans[i][j]);
        }
    cout << ans[N][W];
    return 0;
}
