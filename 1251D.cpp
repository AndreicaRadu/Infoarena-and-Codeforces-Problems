#include <bits/stdc++.h>
using namespace std;
 
long long n , s;
vector<pair<int, int>> v;
 
bool f(long long mid)
{
    long long sum = 0;
    int count = 0;
    vector <int> x;
    for(int i=0 ; i<n ; i++)
    {
        if(v[i].second < mid)
            sum += v[i].first;
        else if(v[i].first >= mid)
        {
            sum += v[i].first;
            count++;
        }
        else
            x.push_back(v[i].first);
    }
 
    sort(x.begin(), x.end());
 
    int need = max(0LL, (n+1)/2 - count);
    if(need > x.size())
        return false;
    for(int i=0 ; i<x.size() ; i++)
    {
        if(i < x.size() - need)
            sum += x[i];
        else
            sum += mid;
    }
 
    return sum <= s;
}
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> s;
        v.resize(n);
        for(int i=0 ; i<n ; ++i)
            cin >> v[i].first >> v[i].second;
 
        sort(v.begin() , v.end());
        long long left = 1, right = 1e15 , mid , ans=0;
        while(left <= right)
        {
            mid = (left + right)/2;
            if(f(mid))
            {
                left = mid + 1;
                ans = mid;
            }
            else right = mid - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
