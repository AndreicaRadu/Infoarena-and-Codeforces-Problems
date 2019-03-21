#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("disjoint.in"); ofstream fout("disjoint.out");

int t[100001], rang[100001];
int caut(int x)
{
	int a=x, b;
    while(t[a]!=a) a=t[a];
	while(t[x]!=x)
	{
		b=t[x];
		t[x]=a;
		x=b;
	}
	return a;
}

void unesc(int x, int y)
{
	if (rang[x]>rang[y]) t[y]=x;
    else t[x]=y;
	if (rang[x]==rang[y]) rang[y]++;
}

int main()
{
	int n,m,i,j,x,y,k;
	fin>>n>>m;
	for (i=1;i<=n;i++) {t[i]=i; rang[i]=1;}
    for (i=1;i<=m;i++)
	{
		fin>>k>>x>>y;
        if(k==2)
        {
			if(caut(x)==caut(y)) fout<<"DA"<<"\n";
            else fout<<"NU"<<"\n";
		}
        else if(caut(x)!=caut(y)) unesc(caut(x), caut(y));
    }
    return 0;
}
