#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("dfs.in"); ofstream fout("dfs.out");
vector <vector<int>>g(100010);
void citire(int n)
{
    for(int i=0 ; i<n ; i++)
    {
        int a, b;
        fin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
int f[100010] = {0};
vector<int> a;
void dfs(int x)
{
    f[x] = 1;
    a.push_back(x);
    for(int i=0 ; i<g[x].size() ; i++)
    {
        if(!f[g[x][i]])
        {
            f[g[x][i]] = 1;
            a.push_back(g[x][i]);
            dfs(g[x][i]);
        }
    }
}
int main()
{
    int n , m , ans = 0;
    fin>>n>>m;
    citire(m);
    dfs(1);
    ans++;
    int i = 2;
    while(i<=n)
    {
        if(f[i]) i++;
        else
        {
            dfs(i);
            ans++;
        }
    }
    fout<<ans;
}