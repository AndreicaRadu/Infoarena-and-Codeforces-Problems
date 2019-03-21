//Quicksort
#include <iostream>
#include <fstream>
#include<time.h>
using namespace std;
int n,v[500005];
int pivot(int st,int dr){
    int x,y,z;
    x=rand()%(dr-st+1)+st;
    y=rand()%(dr-st+1)+st;
    z=rand()%(dr-st+1)+st;
    if(v[x]<=v[y] && v[x]<=v[z])
        {
            if(v[y]<=v[z]) return v[y];
            else return v[z];
        }
    if(v[y]<=v[x] && v[y]<=v[z])
        {
            if(v[x]<=v[z]) return v[x];
            else return v[z];
        }
    if(v[z]<=v[x] && v[z]<=v[y])
        {
            if(v[x]<=v[y]) return v[x];
            else return v[y];
        }
}
void quicksort(int st,int dr){
    int p=pivot(st,dr),i=st,j=dr,aux;
    while(i<=j)
    {
        while(v[i]<p) ++i;
        while(v[j]>p) --j;
        if(i<=j)
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            ++i; --j;
        }
    }
    if(j>st)quicksort(st,j);
    if(i<dr)quicksort(i,dr);
}
int main()
{
    ifstream fin("algsort.in"); ofstream fout("algsort.out");
    int i,n; fin>>n;
    for(i=1;i<=n;i++) fin>>v[i];
    srand(time(NULL));
    quicksort(1,n);
    for(i=1;i<=n;i++) fout<<v[i]<<' ';
}
