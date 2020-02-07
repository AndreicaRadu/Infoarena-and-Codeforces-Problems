#include <bits/stdc++.h>
using namespace std;
long long vv[2010];
int n;
int v[2010];
void norm()
{
    map <long long , int > m;
    int k = 1;
    for(int i=0 ; i<n ; i++)
    {
        if(!m[vv[i]])
        {
            m[vv[i]] = k;
            v[i] = k;
            k++;
        }
        else v[i] = m[vv[i]];
    }
}
bool dif(int l , int r)
{
    int a[2001] = {0};
    bool tr = true;
    for(int i=0 ; i<n ; i++)
    {
        if(i == l && l!=r)
        {
            i = r-1;
            continue;
        }
        if(a[v[i]])
        {
            tr = false;
            break;
        }
        else a[v[i]] = 1;
    }
    return tr;
}
int main()
{
    cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> vv[i];
    norm();
    v[n] = 2000; v[n+1] = 2001;
    //cout << v[0]  << v[1]  << v[2]  << v[3];
    if(dif(n+1 , n+1))
    {
        cout << 0;
        return 0;
    }
    int i=0 , j=0 , min = 2000;
    while(i<n)
    {
        while (!dif(i, j) && j < n)
            j++;
        if (j - i < min && dif(i , j))
            min = j - i;
        i++;
    }
    cout << min;
}
