#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long n , k , ans=0;
    cin >> n >> k;
    vector<long long> c(n) , ord(n);
    set<pair<long long , long long>> s;
    for(int i=0 ; i<n ; i++)
        cin >> c[i];
    long long a = 0;
    for(int i=0 ; i<n+k ; i++)
    {
        ans += a;
        if(i < n)
        {
            a += c[i];
            s.insert(make_pair(c[i] , i));
        }
        if(i >= k)
        {
            a -= prev(s.end())->first;
            ord[prev(s.end())->second] = i+1;
            s.erase(prev(s.end()));
        }
    }
    cout << ans << "\n";
    for(int i:ord)
        cout << i << " ";
    return 0;
}
