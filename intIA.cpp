#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("int.in"); ofstream fout("int.out");
 
int main()
{
    int n;
    fin >> n;
    vector <pair <int , int>> v(n);
    for(int i=0 ; i<n ; i++)
        fin >> v[i].second >> v[i].first;
    sort (v.begin(), v.end());
 
    int ans=1 , a = v[0].first;
    for(int i=1 ; i<n ; i++)
        if(v[i].second >= a)
        {
            ans++;
            a = v[i].first;
        }
    fout << ans;
    return 0;
}
