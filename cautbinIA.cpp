#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int v[100100] , n;
int cautbin0(int x)
{
    int mid , left , right , ans = -1;
    left = -1; right = n;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(v[mid] == x) ans = mid;
        if(v[mid]>x) right = mid-1;
        else left = mid+1;
    }
    return ans;
}
 
int cautbin1(int x)
{
    int mid , left , right , ans = -1;
    left = -1; right = n;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(v[mid] <= x) ans = mid;
        if(v[mid]>x) right = mid-1;
        else left = mid+1;
    }
    return ans;
}
 
int cautbin2(int x)
{
    int mid , left , right , ans = -1;
    left = -1; right = n;
    while(left <= right)
    {
        mid = (left + right)/2;
        if(v[mid] >= x) ans = mid;
        if(v[mid]>=x) right = mid-1;
        else left = mid+1;
    }
    return ans;
}
int main()
{
    ifstream cin("cautbin.in"); ofstream cout("cautbin.out");
    int i,k,l,m;
    cin>>n;
    for(i=1;i<=n;i++) cin>>v[i];
    cin>>k;
    for(i=0;i<k;i++)
    {
        cin>>l; cin>>m;
        if(l==0) cout<<cautbin0(m)<<"\n";
        if(l==1) cout<<cautbin1(m)<<"\n";
        if(l==2) cout<<cautbin2(m)<<"\n";
    }
    return 0;
 
}
