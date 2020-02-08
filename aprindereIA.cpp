#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("aprindere.in"); ofstream fout("aprindere.out");
 
int main()
{
    int n, m , v[1010] = {0} , ans=0;
    fin >> n >> m;
    for(int i=0 ; i<n ; i++)
        fin >> v[i];
    for(int i=0 ; i<m ; i++)
    {
        int a , b , nr;
        fin >> a >> b >> nr;
        if (v[a] == 0)
        {
            ans += b;
            for(int j=0 ; j<nr ; j++)
            {
                int aux;
                fin >> aux;
                v[aux] = 1 ^ v[aux];
            }
        }
        else
            for(int j=0 ; j<nr ; j++)
            {
                int aux;
                fin >> aux;
            }
    }
    fout << ans;
}
