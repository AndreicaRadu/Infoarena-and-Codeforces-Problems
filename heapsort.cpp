//Heapsort
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("algsort.in");ofstream fout("algsort.out");
int i=2,j,n,v[1000100];
void push(int x)
{
    v[i]=x;
    int i0=i;
    while(v[i0/2]>v[i0] && i0/2>0)
    {
        swap(v[i0/2],v[i0]);
        i0=i0/2;
    }
    i++;
}
void pop_varf()
{
    fout<<v[1]<<" ";
    i=1;
    while(j<n)
    {
        if(v[2*i]!=0 && v[2*i]<=v[2*i+1])
            {v[i]=v[2*i]; i=2*i;}
        else if(v[2*i]>=v[2*i+1] && v[2*i+1]!=0)
            {v[i]=v[2*i+1]; i=2*i+1;}
        else if(v[2*i]!=0)
            {v[i]=v[2*i]; i=2*i;}
        else if(v[2*i+1]!=0)
            {v[i]=v[2*i+1];i=2*i+1;}
        else break;
    }
    v[i]=0;
}
int main()
{
    int a;
    fin>>n;fin>>v[1];
    for(j=2;j<=n;j++) {fin>>a; push(a);}
    for(j=1;j<=n;j++) pop_varf();
}
