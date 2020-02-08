#include <bits/stdc++.h>
using namespace std;
 
int n;
vector <int> v;
 
pair<int , int> find()
{
    int ans = n+2 , p;
    for(int i=0 ; i<n-1 ; i++)
    {
        if(v[i] == v[i+1])
            i++;
        else
        {
            ans = i;
            break;
        }
    }
    if(ans == n+2)
        return {n+2 , n+2};
    for(int i=ans+1 ; i<n ; i++)
        if(v[i] == v[ans])
            p = i;
    return {ans , p};
}
int main()
{
    int ans = 0;
    cin >> n;
    n *= 2;
    v.resize(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];
    pair <int , int> aux = {0 , 0};
    while(1)
    {
        aux = find();
        if(aux.first == n+2)
            break;
        for(int i=aux.second-1 ; i>aux.first ; i--)
        {
            swap(v[i] , v[i+1]);
            ans++;
        }
    }
    cout << ans;
}
