#include <iostream>
#include <map>
using namespace std;
int main()
{
    int n,a[1010],i,Max=0; string nume[1010],winner;
    cin>>n;
    map<string,int>scor; map<string,int>v;
    for(i=0;i<n;i++)
    {
        cin>>nume[i]>>a[i];
        scor[nume[i]]+=a[i];
    }
    for(i=0;i<n;i++)
        if(scor[nume[i]]>Max) Max=scor[nume[i]];
    for(i=0;i<n;i++)
    {
        v[nume[i]]+=a[i];
        if(v[nume[i]]>=Max && scor[nume[i]]==Max)
        {
            winner=nume[i];
            break;
        }
    }
    cout<<winner;
}
