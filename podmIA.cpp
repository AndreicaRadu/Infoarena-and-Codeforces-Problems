#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("podm.in"); ofstream fout("podm.out");
int n;
long long mat[1000][1000];
vector <long long> v;
 
void calc(int l , int r)
{
    long long m = LLONG_MAX;
    for(int i=0 ; i<r-l ; i++)
    {
        long long aux = mat[l][l+i] + mat[l+i+1][r] + v[l-1] * v[l+i] * v[r];
        if(m > aux) m = aux;
    }
    mat[l][r] = m;
}
 
int main()
{
    fin >> n;
    v.resize(n+1);
    for(int i=0 ; i<=n ; i++)
        fin >> v[i];
    for(int d=0 ; d<n+1 ; d++)
        for(int i=1 ; i<n+1 ; i++)
        {
            if(d != 0 && i+d < n+1)
                calc(i , i+d);
        }
    fout << mat[1][n];
    return 0;
}
