#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
ifstream fin("reinvent.in");
ofstream fout("reinvent.out");

vector <vector<int>> G(100010);
queue <int> q;
int n , m , x , v[100100];
void citire()
{
    for(int i=0 ; i<m ; i++)
    {
        int a , b;
        fin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i=1 ; i<=x ; i++)
    {
        int nod;
        fin >> nod;
        q.push(nod);
        v[nod] = i;
    }
}
vector <int> d(100010);
void bfs ()
{
    int nod;
    while (!q.empty())
    {
        nod = q.front();
        q.pop();
        for (int i=0 ; i<G[nod].size() ; i++)
        {
            if (!v[G[nod][i]]) {
                v[G[nod][i]] = v[nod];
                d[G[nod][i]] = d[nod] + 1;
                q.push(G[nod][i]);
            } else if (v[G[nod][i]] != v[nod]) {
                fout << d[G[nod][i]] + d[nod] + 1;
                while (!q.empty())
                    q.pop();
                break;
            }
        }
    }
}

int main()
{
    fin >> n >> m >> x;
    citire();
    bfs();
    return 0;
}