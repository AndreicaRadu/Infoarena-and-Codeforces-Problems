#include <bits/stdc++.h>
using namespace std;
 
bool isprime(long long x)
{
    for(int i=2 ; i<=(long long)sqrt(x) ; i++)
    {
        if(x%i == 0)
            return false;
    }
    return x != 1;
}
int main()
{
    int n;
    map <long long , int> mp;
    cin >> n;
    long long a , b;
    for(int i=0 ; i<n ; i++)
    {
        cin >> a;
        if(mp[a] == 1)
        {
            cout << "YES" << "\n";
            continue;
        }
        if(mp[a] == 2)
        {
            cout << "NO" << "\n";
            continue;
        }
        b = (long long)sqrt(a);
        if(b * b == a && isprime(b))
        {
            cout << "YES" << "\n";
            mp[a] = 1;
        }
        else {
            cout << "NO" << "\n";
            mp[a] = 2;
        }
    }
    return 0;
}
