#include <iostream>

using namespace std;

int main()
{
    int v[100010],M=0,i,j=0,c=0,s=0,n,t;
    cin>>n>>t;
    for(i=1;i<=n;i++) cin>>v[i];
    while(s+v[j+1]<=t&&j<n)
    {
        j++;
        s=s+v[j];
    }
    c=j; M=c;
    for(i=2;i<=n;i++)
    {
        s=s-v[i-1];
        while(s+v[j+1]<=t&&j<n)
        {
            j++;
            s=s+v[j];
        }
        c=j-i+1;
        if(c>M) M=c;
    }
    cout<<M;
}
