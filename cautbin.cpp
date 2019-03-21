#include <iostream>
#include <fstream>
using namespace std;
int v[100001],n;
int cautbin0(int x)
    {
        int k,a,b;
        k=1; a=1; b=n;
        while(a<b-1)
        {
            k=(a+b)/2;
            if(v[k]>x) b=k;
            else a=k;
        }
        if(v[b]==x) return b; else if(v[a]==x) return a;
        else return -1;
    }
int cautbin1(int x)
    {
        int a,b,k;
        k=1; a=1; b=n;
        while(a<b-1)
        {
            k=(a+b)/2;
            if(v[k]>x) b=k;
            else a=k;
        }
        if(v[b]==x) return b; else return a;
    }
int cautbin2(int x)
    {
        int a,b,k;
        k=1; a=1; b=n;
        while(a<b-1)
        {
            k=(a+b)/2;
            if(v[k]>=x) b=k;
            else a=k;
        }
        if(v[a]>=x) return a;else return b;
    }

int main()
{
    ifstream fin("cautbin.in"); ofstream fout("cautbin.out");
    int i,k,l,m;
    fin>>n;
    for(i=1;i<=n;i++) fin>>v[i];
    fin>>k;
    for(i=0;i<k;i++)
    {
        fin>>l; fin>>m;
        if(l==0) fout<<cautbin0(m)<<"\n";
        if(l==1) fout<<cautbin1(m)<<"\n";
        if(l==2) fout<<cautbin2(m)<<"\n";
    }
    return 0;

}
