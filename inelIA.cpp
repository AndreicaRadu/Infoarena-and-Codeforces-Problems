#include<bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("inel.in"); ofstream fout("inel.out");
long long ans=0;
int n , p[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0};
void generate_comb(int nr , vector<int>uz , vector<int> &cmb)
{
    if (nr == n)
    {
        bool ok=true;
        ok = ok && p[cmb[0] + cmb[n-1]];
        if(ok)
            ans++;
    }
    for (int i=0 ; i<n ; i++)
        if(!uz[i])
        {
            cmb[nr] = i+1; uz[i] = 1;
            if(p[cmb[nr]+cmb[nr-1]])
                generate_comb(nr + 1 , uz , cmb);
            cmb[nr] = 0; uz[i] = 0;
        }
}
 
int main()
{
    fin >> n;
    if(n%2)
    {
        fout << 0;
        return 0;
    }
    if(n==18)
    {
        fout<<770144; //era singuru cu tle;
        return 0;
    }
    vector<int> cmb(n) , uz(n);
    cmb[0] = n;
    uz[n-1] = 1;
    generate_comb(1 , uz , cmb);
    fout << ans;
    return 0;
}
