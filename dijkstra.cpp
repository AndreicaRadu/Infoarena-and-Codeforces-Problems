#include <fstream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

int n, m;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> G[50010];
int dist[50010];

void read()
{
    fin>>n>>m;
    for (int i=0 ; i<m ; i++)
    {
        int a , b , c;
        fin >> a >> b >> c;
        G[a].push_back(make_pair(b , c));
    }
}
void dijk()
{
    memset(dist , INF,  sizeof(dist));
    dist[1] = 0;
    set<pair<int, int>> h;
    h.insert(make_pair(0 , 1));
    while (!h.empty())
    {
        int node = h.begin()->second;
        h.erase(h.begin());
        vector<pair<int, int>>::iterator it;
        for (it=G[node].begin() ; it!=G[node].end() ; ++it)
        {
            int a = it->first;
            int c = it->second;
            if (dist[a] > dist[node] + c)
            {
                if (dist[a] != INF)
                    h.erase(h.find(make_pair(dist[a] , a)));

                dist[a] = dist[node] + c;
                h.insert(make_pair(dist[a] , a));
            }
        }
    }
}
int main()
{
    read();
    dijk();

    for (int i=2 ; i<=n ; ++i)
    {
        if (dist[i] == INF)
            dist[i] = 0;
        fout << dist[i] << ' ';
    }
}