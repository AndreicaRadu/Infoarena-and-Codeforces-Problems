#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <long long> mon(n+2);
        mon[n+1] = LLONG_MAX;
        for(int i=0 ; i<n ; i++)
            cin >> mon[i];
        int m;
        cin >> m;
        vector <long long> hp(m+2) , he(m+2);
        vector<long long> maxp(n+1 , 0);
        for(int i=0 ; i<m ; i++)
            cin >> hp[i] >> he[i] , maxp[he[i]] = max(maxp[he[i]] , hp[i]);
        for(int i=n-1 ; i>=0 ; i--)
            maxp[i] = max(maxp[i] , maxp[i+1]);
        int ans=0 , curr=-1;
        bool ok=true;
        while(curr<n-1)
        {
            ans++;
            if(maxp[1] < mon[curr+1])
            {
                ok = false;
                break;
            }
            int b=0;
            long long mmon = mon[curr + 1];
            while(maxp[b+1] >= max(mmon , mon[curr + 1 + b]))
            {
                b++;
                mmon = max(mmon , mon[curr + b]);
            }
            curr = curr + b;
        }
        if(ok) cout << ans << "\n";
        else cout << -1 << "\n";
    }
}
