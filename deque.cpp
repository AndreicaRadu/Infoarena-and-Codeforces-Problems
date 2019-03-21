#include <iostream>
#include <fstream>
using namespace std;
int v[5000002],u[5000002],n,k;
int main()
{
    ifstream fin("deque.in"); ofstream fout("deque.out");
    int x=1,y=0,i;
    long long s=0;
    fin>>n>>k;
    for(i=1;i<=n;i++) fin>>v[i];
    for(i=1;i<=n;i++)
    {
        while(x<=y&&v[i]<=v[u[y]]) y--;
        u[++y]=i;
        if(u[x]==i-k) ++x;
        if(i>=k) s=s+v[u[x]];
    }
    fout<<s;
}
