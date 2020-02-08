#include <bits/stdc++.h>
using namespace std;
int n , q;
vector <pair <char , char>> spells;
vector <char> ch;
 
int pos(int ini)
{
    for(int i=0 ; i<q ; i++)
    {
        if(spells[i].first == ch[ini])
        {
            if(spells[i].second == 'L')
                ini--;
            if(spells[i].second == 'R')
                ini++;
        }
    }
    return ini;
}
 
int main()
{
    cin >> n >> q;
    ch.resize(n+2); spells.resize(q);
    for(int i=0 ; i<n ; i++)
        cin >> ch[i+1];
    for(int i=0 ; i<q ; i++)
        cin >> spells[i].first >> spells[i].second;
    int left = 0 , right = n+1 , ansl = 0 , ansr=n+1;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(pos(mid) == 0)
        {
            ansl = max(ansl , mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    left = 0; right = n+1;
    while(left <= right)
    {
        int mid = (left + right)/2;
        if(pos(mid) == n+1)
        {
            ansr = min(ansr , mid);
            right = mid - 1;
        }
        else left = mid + 1;
    }
    cout << n - ansl - (n - ansr + 1);
}
