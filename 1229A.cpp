#include<bits/stdc++.h>
using namespace std;
int g[7001][7001];
int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 0;
        return 0;
    }
    vector <long long> a , b;
    for(int i=0 ; i<n ; i++)
    {
        long long x; cin >> x;
        a.push_back(x);
    }
    long long sumb = 0;
    for(int i=0 ; i<n ; i++)
    {
        long long x; cin >> x;
        b.push_back(x);
        sumb += x;
    }
    int f[7010] = {0};
    long long M=0;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
            if(a[i] & (a[i]^a[j]) || i==j)
            {
                g[i][j] = 1;
                f[i]++;
            }
    set <int> s;
    int k=0;
    while(k < n)
    {
        s.insert(k);
        k++;
    }
    for(int i=n ; i>0 ; i--)
    {
        for(int j:s)
        {
            if(f[j] == s.size())
            {
                s.erase(j);
                for(int l:s)
                    if(g[l][j])
                        f[l]--;
                break;
            }
        }
    }
    if(s.size()>1)
        for(int i:s)
            M += b[i];
    cout << M;
}
