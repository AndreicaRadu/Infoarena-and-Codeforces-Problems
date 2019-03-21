#include <iostream>
#include <fstream>
#include <map>
using namespace std;
ifstream fin("eqs.in"); ofstream fout("eqs.out");
int main()
{
    map <int,int>m;
    int a1,a2,a3,a4,a5, s, i,j,l, a=0;
    fin>>a1>>a2>>a3>>a4>>a5;
    for(i=-50;i<=50;i++) if(i!=0)
        for(j=-50;j<=50;j++) if(j!=0)
        {
            int s=a4*i*i*i+a5*j*j*j;
            m[s]++;
        }
    for(i=-50;i<=50;i++) if(i!=0)
        for(j=-50;j<=50;j++) if(j!=0)
            for (l=-50;l<=50;l++) if(l!=0)
            {
                s=-(a1*i*i*i+a2*j*j*j+a3*l*l*l);
                if(m.find(s)!=m.end()) a+=m[s];
            }
    fout<<a;
}
