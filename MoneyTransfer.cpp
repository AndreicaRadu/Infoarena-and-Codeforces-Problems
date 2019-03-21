#include <iostream>
#include <map>
using namespace std;
long long v[100002],u[100002],n,c=0,d=0;
map<long long,int>m;
void check(int x)
{
    int i; d=d+x; c=0;
    c=m[-d];
}

int main()
{
    int i,M;
    cin>>n;
    for(i=1;i<=n;i++) cin>>v[i];
    u[1]=v[1];m[u[1]]++;
    for(i=2;i<=n;i++) {u[i]=u[i-1]+v[i];m[u[i]]++;}
    check(0);M=c;
    for(i=n;i>1;i--)
    {
        check(v[i]);
        if(c>M) M=c;
    }
    cout<<n-M;
}
