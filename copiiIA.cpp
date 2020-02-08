#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("copii.in"); ofstream fout("copii.out");
int n , ans=0;
string g[10];
int cmb[11];
bool ok[12][12];
bool check(int max)
{
    for(int i=1 ; i<=max ; i++)
        for(int j=1 ; j<=max ; j++)
            ok[i][j] = false;
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
            if(g[i][j] == '1')
                ok[cmb[i]][cmb[j]] = true;
        }
    for(int i=1 ; i<=max ; i++)
        for(int j=1 ; j<=max ; j++)
        {
            if(i!= j && !ok[i][j])
                return false;
        }
    return true;
}
 
void bkt(int nr , int maxx)
{
    if(nr == n)
    {
        if(check(maxx))
            ans++;
        return;
    }
 
    for(int i=1 ; i<= maxx + 1 ; i++)
    {
        cmb[nr] = i;
        bkt(nr + 1, max(maxx, i));
    }
}
 
int main()
{
    fin >> n;
    for(int i=0 ; i<n ; i++)
        fin >> g[i];
    bkt(0 , 0);
    fout << ans-1;
    return 0;
}
