#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
double a[1000000];
struct punct
{
    double x,y;
}v[1010];
int main()
{
    ifstream fin("trapez.in"); ofstream fout("trapez.out");
    int N,i,j,k=0,c=1,trap=0;
    fin>>N;
    for(i=1;i<=N;i++) fin>>v[i].x>>v[i].y;
    for(i=1;i<=N;i++)
        for(j=i+1;j<=N;j++)
            a[k++]=(v[j].x-v[i].x)/(v[j].y-v[i].y);
    sort(a,a+k);
    for(i=0;i<k;i++)
    {
        if(a[i]==a[i+1]) c++;
        else {trap=trap+c*(c-1)/2; c=1;}
    }
    fout<<trap;
}
