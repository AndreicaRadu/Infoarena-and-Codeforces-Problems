#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct str
{
    int x , y , c;
};

str v[400010];
int t[200010] , rez[200010];

int cmp(str a , str b)
{
    return a.c < b.c;
}

int rad(int x)
{
    int y = x;
    while(x != t[x])
        x = t[x];
    while(t[y] != x)
    {
        int aux = t[y];
        t[y] = x;
        y = aux;
    }
    return x;
}

int main()
{
    ifstream fin("apm.in");
    ofstream fout("apm.out");
    int n , m , k = 0 , sum=0;
    fin >> n >> m;
    for(int i=1 ; i<=m ; i++)
        fin >> v[i].x >> v[i].y >> v[i].c;
    for(int i=1 ; i<=n ; i++)
        t[i] = i;
    sort(v+1 , v+m+1 , cmp);
    for(int i=1 ; i<=m && k < n-1 ; i++)
    {
        int x , y;
        x = rad(v[i].x);
        y = rad(v[i].y);
        if(x == y) continue;
        t[x] = y;
        sum = sum + v[i].c;
        k++;
        rez[k] = i;
    }
    fout << sum << "\n" << n-1 << "\n";
    for(int i=1 ; i<=n-1 ; i++)
        fout << v[rez[i]].x << " " << v[rez[i]].y << "\n";
}