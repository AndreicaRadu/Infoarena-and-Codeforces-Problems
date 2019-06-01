#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ifstream fin("distante.in");
    ofstream fout("distante.out");
    int k, n, m, s;
    fin >> k;
    for (int j=0 ; j<k ; j++)
    {
        fin >> n >> m >> s;
        vector <int> d(n+1 , 1010);
        vector < vector< pair<int, int>>> G(n+1);
        for (int i=1 ; i<=n ; i++)
            fin >> d[i];
        for (int i=0 ; i<m ; i++)
        {
            int x , y , cost;
            fin >> x >> y >> cost;
            G[x].push_back(make_pair(cost , y));
            G[y].push_back(make_pair(cost , x));
        }
        queue <int> Q;
        Q.push(s);
        int ok = 0 , f[50010] = {0}; f[s] = 1;
        while (!Q.empty())
        {
            ok++;
            int nod = Q.front();
            Q.pop();
            for (int i=0 ; i<G[nod].size() ; i++)
            {
                if (d[nod] + G[nod][i].first == d[G[nod][i].second])
                {
                    f[G[nod][i].second] = 1;
                    Q.push(G[nod][i].second);
                }
            }
        }
        if (ok < n)
            fout << "NU" << "\n";
        else
            fout << "DA" << "\n";
    }
    return 0;
}