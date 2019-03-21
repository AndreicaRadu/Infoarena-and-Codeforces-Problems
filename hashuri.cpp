#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector <int> H[694201];

int exista(int x)
{
    int i, y=x%694201;
    for(i=0;i<H[y].size();i++)
        if(H[y][i]==x) return 1;
    return 0;
}
void insereaza(int x)
{
    int y=x%694201;
    if(exista(x)==0) H[y].push_back(x);
}
void elimina(int x)
{
    int i, y=x%694201;
    for(i=0;i<H[y].size();i++)
        if (H[y][i]==x) H[y][i]=0;
}
int main()
{
    ifstream fin("hashuri.in"); ofstream fout("hashuri.out");
    int N,i,a,b;
    fin>>N;
    for(i=1;i<=N;i++)
    {
        fin>>a>>b;
        if(a==1) insereaza(b);
        if(a==2) elimina(b);
        if(a==3) fout<<exista(b)<<"\n";
    }
}
