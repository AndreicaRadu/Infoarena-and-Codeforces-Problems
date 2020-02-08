#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int w, m;
    cin >> w >> m;
    int aux = m;
    vector<int> v;
    while(aux > 0)
    {
        v.push_back(aux%w);
        aux /= w;
    }
    v.push_back(0);
    for(int i=0 ; i<v.size() ; i++)
        if(v[i] > 1)
        {
            if(v[i] != w-1 && v[i] != w)
            {
                cout << "No";
                return 0;
            }
            else
                v[i+1]++;
        }
    cout << "Yes";
}
