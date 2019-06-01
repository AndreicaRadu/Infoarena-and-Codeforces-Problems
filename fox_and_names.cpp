#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int tab[26][26] , n , a = 0 , deg[26];;
string s[110];
bool k = true;

void solve(int beg , int end , int ind)
{
    for(int i=beg ; i<end ; i++)
        //for(int j=i+1 ; j<=end ; j++)
        {
            int j=i+1;

            if(s[i].size() <= ind || s[j].size() <= ind)
            {
                if(s[i].size() > s[j].size())
                {
                    k = false;
                    i = end +1;
                    break;
                }
            }
            else if(s[i][ind] == s[j][ind])
            {
                int aux = ind;
                while(s[i][aux+1] == s[j][aux+1])
                    aux++;
                solve(i , j , aux+1);
            }
            else if(tab[(int)s[i][ind] - 97][(int)s[j][ind] - 97] == -1)
            {
                k = false;
                i = end +1;
                break;
            }
            else if(!tab[(int)s[i][ind] - 97][(int)s[j][ind] - 97])
            {
                tab[(int) s[i][ind] - 97][(int) s[j][ind] - 97] = 1;
                tab[(int) s[j][ind] - 97][(int) s[i][ind] - 97] = -1;
            }
        }
}
int main()
{
    cin>>n;
    for(int i=0 ; i<n ; i++)
        cin>>s[i];

    solve(0 , n-1 , 0);

    if(!k)
    {
        cout << "Impossible";
        return 0;
    }
    vector <vector <int>> G(50010);
    queue<int> a;
    for(int i=0 ; i<26 ; i++)
        for(int j=0 ; j<26 ; j++)
            if(tab[i][j] == 1)
            {
                G[i].push_back(j);
                deg[j]++;
            }

    for(int i=0 ; i<26 ; i++)
        if(deg[i] == 0)
            a.push(i);

    char ans[26];
    int nr = 0;
    while(!a.empty())
    {
        int aux;
        ans[nr] = (char)(a.front()+97);
        nr++;
        aux = a.front();
        a.pop();

        for(int j=0 ; j<G[aux].size() ; j++)
        {
            deg[G[aux][j]]--;
            if(deg[G[aux][j]]==0)
                a.push(G[aux][j]);
        }
    }
    if(nr == 26)
        for(int i=0 ; i<26 ; i++)
            cout << ans[i];
    else cout << "Impossible";
}