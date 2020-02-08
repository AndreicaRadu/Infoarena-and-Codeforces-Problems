#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("transport.in"); ofstream fout("transport.out");
int n,k;
vector<int> v;
int transp(int sz)
{
    int x=0 , nrt=1;
    for(int i=0 ; i<n ; i++)
    {
        x += v[i];
        if(x > sz)
        {
            nrt++;
            x = v[i];
        }
        if(nrt > k) return 0;
    }
    return 1;
}
int cautbin(int left , int right)
{
    int mid , ans=1000000000;
    while(left <= right)
    {
        mid=(right + left)/2;
        if(transp(mid)==0) left = mid+1;
        else
        {
            right = mid-1;
            ans = min(mid , ans);
        }
    }
    return ans;
}
int main()
{
    fin >> n >> k;
    int mx=0;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        fin >> x;
        v.push_back(x);
        if(mx < x)
            mx = x;
    }
    fout << cautbin(mx ,1000000000);
    return 0;
}
