#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int k1 , k2 , k3 , aux;
    cin >> k1 >> k2 >> k3;
    int n = k1 + k2 + k3;
    vector<int> f(n);
    while(k1--) cin >> aux , f[aux - 1] = 0;
    while(k2--) cin >> aux , f[aux - 1] = 1;
    while(k3--) cin >> aux , f[aux - 1] = 2;
 
    int ans = 0 , m = 0;
    for(int i = 0; i < n; i++)
        if(f[i] != 2)
            ans++;
    int l[3]={0,0,0} , r[3]={0,0,0};
    for(int i = 0; i < n; i++)
        r[f[i]]++;
    for(int i=0 ; i<n ; i++)
    {
        l[f[i]]++;
        r[f[i]]--;
        m = max(m , l[0] - l[1]);
        ans = min(ans, r[0] + r[1] + l[2] + l[0] - m);
    }
 
    cout << ans << endl;
}
