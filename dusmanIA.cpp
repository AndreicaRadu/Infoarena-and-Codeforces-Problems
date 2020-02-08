#include<bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("dusman.in"); ofstream fout("dusman.out");
 
int n , m , k , g[1010][1010] = {0} , ok=0 , done=0;
void generate_comb(int nr , int n , vector<int>uz , vector<int> &cmb)
{
    if(done) return;
    if (nr == n)
    {
        ok++;
        if(ok == k)
        {
            done = 1;
            for (int i = 0; i < n; i++)
                fout << cmb[i]+1 << " ";
        }
        return;
    }
    for (int i=0 ; i<n ; i++)
        if(!uz[i])
        {
            cmb[nr] = i; uz[i] = 1;
            if(!g[cmb[nr]][cmb[nr-1]])
                generate_comb(nr + 1 , n , uz , cmb);
            if(done) break;
            cmb[nr] = 0; uz[i] = 0;
        }
}
 
int main()
{
    fin >> n >> k >> m;
    for(int i=0 ; i<m ; i++)
    {
        int a , b;
        fin >> a >> b;
        g[a-1][b-1] = 1;
        g[b-1][a-1] = 1;
    }
    vector<int> cmb(n) , uz(n);
    generate_comb(0 , n , uz , cmb);
    return 0;
}
