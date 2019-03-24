#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("graf.in");
ofstream fout("graf.out");

vector< vector <int> > g;
int n,m;

void citire()
{
    for(int i=0 ; i<m ; i++)
    {
        int a, b;
        fin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
vector <int> BFS(int s)
{
    vector <int> d(n+1,n);
    queue <int> q;
    d[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int nod = q.front();
        q.pop();
        for(int i=0 ; i<g[nod].size() ; i++)
        {
            int vec = g[nod][i];
            if(d[vec]==n)
            {
                d[vec] = d[nod] +1;
                q.push(vec);
            }
        }
    }
    return d;
}
int main()
{
    int x,y;
    fin>>n>>m>>x>>y;
    g = vector<vector<int > >(n + 1);
    citire();
    vector <int> xv = BFS(x);
    vector <int> yv = BFS(y);
    vector <int> bune;
    for(int i=1 ; i<=n ; i++)
    {
        if(xv[i]+yv[i] == xv[y])
            bune.push_back(i);
    }
    for(int i=0 ; i<bune.size() ; i++)
    {
        int a = 1;
        for(int j=i+1 ; j<bune.size() ; j++)
        {
            if(xv[bune[i]] == xv[bune[j]])
            {
                bune[j] = 0;
                a = 0;
            }
        }
        if(!a) bune[i] = 0;
    }
    int nr=0;
    for(int i=0 ; i<bune.size() ; i++)
        if(bune[i]!= 0)
            nr++;
    fout<<nr<<"\n";

    for(int i=0 ; i<bune.size() ; i++)
        if(bune[i]!= 0)
            fout<<bune[i]<<" ";
}