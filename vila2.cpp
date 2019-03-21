#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("vila2.in"); ofstream fout("vila2.out");
    int v[100010],d1[100010],d2[100010],n,k,i,j,x=1,y=1,xx=1,yy=1,m=0;
    fin>>n>>k;
    for(i=1;i<=n;i++) fin>>v[i];
    d1[1]=1;
    d2[1]=1;
    for(i=2;i<=n;i++)
    {
        for(j=y;j>=x;j--)
        {
            if(v[d1[j]]>=v[i]) y--;
            else break;
        }
        for(j=yy;j>=xx;j--)
        {
            if(v[d2[j]] <= v[i]) yy--;
            else break;
        }
        d1[++y]=i;
        d2[++yy]=i;
        if(d1[x]==i-k-1) x++;
        if(d2[xx]==i-k-1) xx++;
        if(i>=k+1) m=max(m, v[d2[xx]]-v[d1[x]]);
    }
    fout<<m;
    return 0;
}
