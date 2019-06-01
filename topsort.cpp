#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

unsigned int N , M , deg[50010];

int main()
{
    fin >> N >> M;
    vector <vector <int>> G(50010);
    queue<int> a;

    for(int i=1 ; i<=M ; i++)
    {
        int x , y;
        fin >> x >> y;
        G[x].push_back(y);
        deg[y]++;
    }

    for(int i=1 ; i<=N ; i++)
        if(deg[i] == 0)
            a.push(i);

    while(!a.empty())
    {
        int aux;
        fout << a.front() << " ";
        aux=a.front();
        a.pop();

        for(int j=0 ; j<G[aux].size() ; j++)
        {
            deg[G[aux][j]]--;
            if(deg[G[aux][j]]==0)
                a.push(G[aux][j]);
        }
    }
}