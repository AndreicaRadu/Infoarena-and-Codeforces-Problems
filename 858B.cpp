#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    vector < pair<int,int> > a;
    int n , m;
    cin >> n >> m;
    for(int i=0 ; i<m ; i++)
    {
        int x , y;
        cin >> x >> y;
        a.push_back(make_pair(x , y));
    }
    sort(a.begin() , a.end());
    int k=0 , sz = 102;
 
    int floor=-1 , nrf=0;
    for(int i=1 ; i<101 ; i++)
    {
        bool ok=true;
        for (int j=0; j < a.size(); j++)
        {
            if(a[j].second != (a[j].first-1)/i + 1)
                ok = false;
        }
        if(ok)
        {
            if((n-1)/i +1 != floor)
                nrf++;
            if(nrf > 1) break;
            floor = (n-1)/i +1;
        }
    }
    if(nrf == 1)
        cout << floor;
    else
        cout << -1;
}
