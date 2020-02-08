#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n , k , x, ans = 0 , a[200200] = {0}, pre[200200] = {0}, suf[200200] = {0};
    cin >> n >> k >> x;
    x = pow(x, k);
    for (int i=1 ; i<=n ; i++)
        cin >> a[i];
 
    for (int i=1 ; i<=n ; i++)
        pre[i] = pre[i-1] | a[i];
    for(int i=n ; i>0 ; i--)
        suf[i] = suf[i+1] | a[i];
 
    for(int i=1 ; i<=n ; i++)
        ans = max(ans, pre[i-1] | (a[i] * x) | suf[i+1]);
 
    cout << ans;
}
