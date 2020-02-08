#include <fstream>
#include <iostream>
using namespace std;
int nr0(int n)
{
    int z=0;
    while(n>=5)
    {
       z=z+n/5;
       n=n/5;
    }
    return z;
}
int main()
{
    ifstream fin("fact.in");ofstream fout("fact.out");
    int s,r=0,k;
    fin>>k;s=1<<30;
    while(s)
    {
        if(nr0(r+s)<k) r=r+s;
        s=s/2;
    }
    if(nr0(r+1)==k) fout<<r+1;
    else fout<<-1;
}
