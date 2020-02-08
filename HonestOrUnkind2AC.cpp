#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<vector<pair<int , int>>> s(n+1);
    for(int i=1 ; i<=n ; i++)
    {
        int aux;
        cin >> aux;
        for(int j=0 ; j<aux ; j++)
        {
            int x , y;
            cin >> x >> y;
            s[i].push_back({x , y});
        }
    }
    int ans=0;
    for(long long i=0 ; i<1LL<<n ; i++)
    {
        int hon=0 , curr = 0 , v[20];
        for(int j=0 ; j<=n ; j++)
            v[j] = 0;
        bool ok = true;
        long long aux = i;
        while(aux)
        {
            curr++;
            v[curr] = aux%2;
            aux /= 2;
            if(v[curr] == 1) hon++;
        }
        if(hon <= ans) continue;
        for(int j=1 ; j<=n ; j++)
            if(v[j])
                for(int l=0 ; l<s[j].size() ; l++)
                    if(s[j][l].second != v[s[j][l].first])
                        ok = false;
        if(ok) ans = max(ans , hon);
    }
    cout << ans;
}
