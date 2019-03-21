#include <iostream>
#include <fstream>
using namespace std;
long long n,N,i,i0,j=0,k,Euler,m,p,q,u[12],pas;
long long catecopr(long long x)
{
    long long lim=1LL<<j, a=0;

    for(i=0;i<lim;i++)
    {
        long long b=0,pp=1;

        for(i0=0;i0<j;i0++)
        {
            if(i & (1LL << i0))
            {
                b++; pp*=u[i0];
            }
        }

        if(b%2==0) a=a+x/pp;
        else a=a-x/pp;

        }
    return a;
}

long long cautbin()
{
    long long a;
    while(1)
    {
        a=catecopr(k);
        if(a==p)
        {
            while(p==catecopr(k-1)) k--;
            return k;
        }
        if(a>p) k=k-pas;
        if(a<p) k=k+pas;
        pas=(pas+1)/2;
    }
}
int main()
{
    ifstream fin("frac.in"); ofstream fout("frac.out");
    fin>>n>>m;
    if(n==1) fout<<m;
    else
    {
        Euler=n;N=n;
        for(i=2;n>1;i++)
        {
            if((n/i)*i==n)
            {
                while((n/i)*i==n) n=n/i;
                u[j]=i; j++;
            }
        }

        for(i=0;i<j;i++) Euler=(Euler/u[i])*(u[i]-1);

        p=m%Euler; q=m/Euler;
        pas=(N+1)/2; k=1;

        if(p==0) {i=N-1;q--;}
        else i=cautbin();

        fout<<q*N+i;
    }
}
