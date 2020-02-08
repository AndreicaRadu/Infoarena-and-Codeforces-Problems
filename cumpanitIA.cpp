#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("cumpanit.in"); ofstream fout("cumpanit.out");
long long a,b;
int prim[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
set<long long> ok;
 
void bkt(int sum , int exp , int k , long long nr)
{
    if (sum == exp && nr>a && nr<b)
        ok.insert(nr);
    if (nr * prim[k] > b || k==13) return;
 
    bkt(sum , exp , k+1 , nr);
 
    for (int j=1 ; nr*prim[k]<=b ; j++)
    {
        nr *= prim[k];
        bkt(sum + prim[k] , exp+j , k+1 , nr);
    }
}
int main()
{
    fin >> a >> b;
    bkt(0,0,0,1);
    set<long long>::iterator i;
    for(i=ok.begin() ; i!=ok.end() ; i++)
        fout << *i << "\n";
    return 0;
}
