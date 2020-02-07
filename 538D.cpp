#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main()
{
    int n , k = 0;
    cin >> n;
    string a[101];
    vector <pair <int , int>> P;
    for(int i=0 ; i<n ; i++)
    {
        cin >> a[i];
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'o')
            {
                P.push_back(make_pair(i,j));
                k++;
            }
        }
    }
    vector <pair <int , int>> atac;
    for(int i=-n+1 ; i<n+1 ; i++)
        for(int j=-n+1 ; j<n+1 ; j++)
        {
            bool bun = true;
            for(int l=0 ; l<k ; l++)
            {
                if(P[l].first + i >= 0 && P[l].second + j >= 0 && P[l].first + i < n && P[l].second + j < n)
                {
                    if(a[P[l].first + i][P[l].second + j] == '.')
                    {
                        bun = false;
                        break;
                    }
                }
            }
            if(bun)
            {
                atac.push_back(make_pair(i , j));
            }
        }
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<n ; j++)
        {
            bool este = false;
            if (a[i][j] == 'x')
            {
                for (int l = 0; l < atac.size(); l++)
                {
                    for (int k = 0; k < P.size(); k++) {
                        if (P[k].first + atac[l].first == i && P[k].second + atac[l].second == j) {
                            este = true;
                            break;
                        }
                    }
                    if(este) break;
                }
                if(!este)
                {
                   cout << "NO";
                   return 0;
                }
            }
        }
 
    cout << "YES"<<"\n";
    vector<string> ans;
    ans = vector<string> (2*n+1, string(2*n+1, '.'));
 
    for(int i=0 ; i<atac.size() ; i++)
    {
        ans[n + atac[i].first][n + atac[i].second] = 'x';
    }
    ans[n][n] = 'o';
    for(int i=1 ; i<2*n ; i++)
    {
        for (int j = 1; j < 2*n; j++)
            cout << ans[i][j];
        cout << "\n";
    }
    return 0;
}
