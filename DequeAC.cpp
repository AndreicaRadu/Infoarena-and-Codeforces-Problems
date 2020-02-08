#include <bits/stdc++.h>
using namespace std;
long long d[3030][3030];
int main()
{
    int n;
    cin >> n;
    for (int i=1 ; i<=n ; i++)
        cin >> d[i][i];
    for (int i=1 ; i<=n ; i++)
        for (int j=i-1 ; j>0 ; j--)
            d[i][j] = max(d[i][i] - d[i-1][j] , d[j][j] - d[i][j+1]);
    cout << d[n][1];
    return 0;
}
