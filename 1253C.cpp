#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    long long n , m;
    cin >> n >> m;
    vector <long long> sw(n);
    for(int i=0 ; i<n ; i++)
        cin >> sw[i];
    sort(sw.begin() , sw.end());
    vector <long long> sum(n);
    sum[0] = sw[0];
    for(int i=1 ; i<n ; i++)
        sum[i] = sum[i-1] + sw[i];
    vector<long long> ans(n);
    for(int i=0 ; i<n ; i++)
    {
        ans[i] = sum[i];
        if(i >= m)
            ans[i] += ans[i-m];
    }
    for(int i=0 ; i<n ; i++)
        cout << ans[i] << " ";
}
