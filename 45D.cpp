#include <bits/stdc++.h>
using namespace std;
 
int f[10001000];
int main()
{
    int n , ans[110];
    cin >> n;
    vector <pair<pair<int, int>, int>> a(n);
    for (int i=0 ; i<n ; i++)
    {
        cin >> a[i].first.second >> a[i].first.first;
        a[i].second = i;
    }
    sort(a.begin() , a.end());
    for(int i=0 ; i<n ; i++)
    {
        while(f[a[i].first.second])
            a[i].first.second++;
 
        ans[a[i].second] = a[i].first.second;
        f[a[i].first.second] = 1;
    }
    for (int i=0 ; i<n ; i++)
        cout << ans[i] << " ";
}
