#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> G;
map<int , int> vis , dist;
 
int dfs(int x)
{
    if(vis[x] == 1)
        return dist[x];
    for(int i=0 ; i<G[x].size() ; i++)
        dist[x] = max(dist[x] , dfs(G[x][i]) + 1);
    vis[x] = 1;
    return dist[x];
}
 
int main()
{
    int n , m;
    cin>> n >> m;
    G.resize(n+1);
    int ans = 0 , a , b;
    for(int i=0 ; i<m ; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
    }
    for(int i=1 ; i<=n ; i++)
        ans = max(ans , dfs(i));
    cout << ans;
    return 0;
}
