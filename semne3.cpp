#include <iostream>
#include <fstream>
using namespace std;

char semn[500010];
int n, c, ans[500010], f[500010];

void solve(int x)
{
    f[x] = 1;
    if(x < n && semn[x - 1] == '>')
        solve(x + 1);
    c++;
    ans[x] = c;
}

int main()
{
    ifstream fin("semne3.in"); ofstream fout("semne3.out");
    fin >> n;
    for(int i=0 ; i<n ; i++)
        fin >> semn[i];
    for(int i=1 ; i<=n ; i++)
        if(f[i] == 0 )
            solve(i);
    for(int i = 1 ; i <= n ; i++)
        fout<<ans[i] << " ";
}