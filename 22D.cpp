#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("int.in"); ofstream fout("int.out");
 
int main()
{
    int n;
    cin >> n;
    vector <pair <int , int>> v(n);
    for(int i=0 ; i<n ; i++)
    {
        int a , b;
        cin >> a >> b;
        if(a < b)
        {
            v[i].second = a;
            v[i].first = b;
        }
        else
        {
            v[i].second = b;
            v[i].first = a;
        }
    }
    sort (v.begin(), v.end());
 
    vector <int> nails;
    int ans=1 , a = v[0].first;
    nails.push_back(a);
    for(int i=1 ; i<n ; i++)
    {
        if(v[i].first >= a && v[i].second <= a)
            continue;
        else
        {
            ans++;
            a = v[i].first;
            nails.push_back(a);
        }
    }
    cout << ans << "\n";
    for(int i:nails)
        cout << i << " ";
    return 0;
}
