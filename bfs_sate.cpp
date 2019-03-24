#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

ifstream fin("sate.in");
ofstream fout("sate.out");

vector< vector <int> > g;
int n,m;
map<pair<int,int>, int> mp;

void citire()
{
    for(int i=0 ; i<m ; i++)
    {
        int a , b , c;
        fin >> a >> b >>c;
        g[a].push_back(b);
        g[b].push_back(a);
        mp[make_pair(a,b)] = c;
        mp[make_pair(b,a)] = c;
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
    if(x>y)
        swap(x,y);
    g = vector<vector<int > >(n + 1);
    citire();
    vector <int> xv = BFS(x);
    vector <int> yv = BFS(y);

    int drum[30010];
    drum[0] = x;
    drum[yv[x]] = y;
    for(int i=1 ; i<yv[x] ; i++)
    {
        for(int j=0 ; j<g[drum[i-1]].size() ; j++)
        {
            if(xv[g[drum[i-1]][j]] == i && yv[g[drum[i-1]][j]] == yv[x] - i)
            {
                drum[i] = g[drum[i-1]][j];
                break;
            }
        }
    }
    int ans = 0;
    for(int i=0 ; i<yv[x] ; i++)
    {
        if(drum[i]<drum[i+1])
            ans = ans + mp[make_pair(drum[i] , drum[i+1])];
        else ans = ans - mp[make_pair(drum[i] , drum[i+1])];
    }
    fout<<ans;
}