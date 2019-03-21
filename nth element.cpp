#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int v[3000010],n,K;

int partitie(int s, int d)
{
	int i=s-1, j=d+1, p;
	p=v[(rand()%(d-s+1))+s];
    while(1)
	{
		do i++; while(v[i]<p);
        do j--; while(p<v[j]);

		if(i < j) swap(v[i], v[j]);
		else return j;
	}
    return 0;
}

void qs(int s, int d, int k)
{
	if(s==d) return;
    int q=partitie(s, d), t=q-s+1;
	if(t>=k) qs(s, q, k);
	else qs(q+1, d, k-t);
}

int main()
{
    ifstream fin("sdo.in"); ofstream fout("sdo.out");
    fin>>n>>K;
    int i;
    for(i=1;i<=n;i++) fin>>v[i];
	srand(time(NULL));
    qs(1, n, K);
    fout<<v[K];
}
