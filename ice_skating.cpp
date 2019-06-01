#include<iostream>
using namespace std;

int n;
int v[1010];
int p[1010][2];

void dfs(int x)
{
    v[x] = 1;
    for (int i=1 ; i<=n ; i++)
        if (!v[i] && (p[x][0] == p[i][0] || p[x][1] == p[i][1]))
            dfs(i);
}

int main()
{
    cin >> n;
    for (int i=1 ; i<=n ; i++)
        cin >> p[i][0] >> p[i][1];
    int nr = 0;
    for (int i=1 ; i<=n ; i++)
        if (!v[i])
        {
            dfs(i);
            nr++;
        }

    cout << nr-1;
}