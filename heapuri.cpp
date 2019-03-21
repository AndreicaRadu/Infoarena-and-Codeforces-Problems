#include <iostream>
#include <fstream>

using namespace std;

int N, NR, L, A[200010], h[200010], pos[200010];   // h[i] pozitia in heap elm bagat al i-lea
                                                  // A[h[]] min heap
void push(int x)                                 // pos[h[]] si h[pos[]] sunt sirul 1 2 ... n; h si pos sunt inverse
{
	while (x/2 && A[h[x]]<A[h[x/2]])
	{
		swap(h[x],h[x/2]);

		pos[h[x]]=x;
		pos[h[x/2]]=x/2;
		x=x/2;
	}
}

void pop(int x)
{
	int y=0;
    while(x!=y)
	{
		y=x;
        if (y*2<=L && A[h[x]]>A[h[y*2]]) x = y*2;
		if (y*2+1<=L && A[h[x]]>A[h[y*2+1]]) x = y*2+1;

		swap(h[x],h[y]);
        pos[h[x]]=x;
		pos[h[y]]=y;
	}
}

int main()
{
	ifstream fin("heapuri.in"); ofstream fout("heapuri.out");
    int i,x,k;
    fin>>N;
	for(i=1;i<=N;i++)
	{
		fin>>k;
		if(k<3) fin>>x;
        if(k==1)
		{
			L++, NR++;
			A[NR]=x;
			h[L]=NR;
			pos[NR]=L;

			push(L);
		}
        if(k==2)
		{
			A[x]=-1;
			push(pos[x]);

			pos[h[1]]=0;
			h[1]=h[L--];
			pos[h[1]]=1;
			if(L>1) pop(1);
		}
        if(k==3) fout<<A[h[1]]<<"\n";
	}
    return 0;
}
