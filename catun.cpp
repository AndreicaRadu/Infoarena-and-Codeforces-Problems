#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("catun.in");
ofstream fout("catun.out");

int n , m , k , f[36010];
vector <pair<int, int>> v(36010);
vector <vector<pair<int, int>>> G(36010);
queue <int> q;

void citire()
{
    fin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        v[i] = {(1 << 29), (1 << 29)};
    for(int i = 1; i <= k; i++)
    {
        fin >> f[i];
        q.push(f[i]);
        v[f[i]] = {f[i], 0};
    }
    for(int i=1 ; i<=m ; i++)
    {
        int x, y, d;
        fin >> x >> y >> d;
        G[x].push_back({y, d});
        G[y].push_back({x, d});
    }
}
void dij()
{
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(pair<int, int> i : G[nod])
        {
            if(v[nod].second + i.second < v[i.first].second || (v[nod].second + i.second == v[i.first].second && v[nod].first < v[i.first].first))
            {
                v[i.first].first = v[nod].first;
                v[i.first].second = v[nod].second + i.second;
                q.push(i.first);
            }
        }
    }
}
int main()
{
    citire();
    dij();
    for(int i=1 ; i<=k ; i++)
        v[f[i]] = {0 , 0};
    for(int i=1 ; i<=n ; i++)
        if(v[i].first == (1 << 29))
            v[i].first = 0;
    for(int i=1 ; i<=n ; i++)
        fout << v[i].first << ' ';
    return 0;
}