#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n , m;
    cin >> n >> m;
    vector <int> ans;
    vector <pair <pair<int , int> , int>> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i].first.second >> v[i].first.first;
    for(int i=0 ; i<n ; i++)
        v[i].second = i+1;
    sort(v.begin() , v.end());
    for(int i=0 ; i<n ; i++)
        swap(v[i].first.first , v[i].first.second);
    for(int i=v[0].first.second ; i<=200 ; i++)
    {
        int k=0;
        for(int j=0 ; j<n ; j++)
        {
            if (v[j].first.first <= i && v[j].first.second >= i)
            {
                k++;
                if(k > m)
                {
                    v[j].first.first = -100000 - i;
                    v[j].first.second = -100000 - i;
                    ans.push_back(v[j].second);
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(int i:ans)
        cout << i << " ";
}
