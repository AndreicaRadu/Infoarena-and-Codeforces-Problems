#include <bits/stdc++.h>
using namespace std;
 
int n;
vector <pair<long long , pair<long long , long long>>> v;
 
int main()
{
    long long n;
    cin >> n;
    v.resize(n);
    for(int i=0 ; i<n ; i++)
    {
        long long a , b;
        cin >> a >> b;
        v[i].first = a - b;
        v[i].second.first = a;
        v[i].second.second = b;
    }
    sort(v.begin() , v.end() , greater<pair<long long , pair<long long , long long>>>());
    long long ans = v[0].second.first , sum = v[0].second.first;
    for(int i=1 ; i<n ; i++)
    {
 
        sum += v[i].second.first - v[i-1].second.first + v[i-1].second.second;
        ans = max(ans , sum);
    }
    cout << ans;
}
