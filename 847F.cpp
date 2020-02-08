#include <bits/stdc++.h>
using namespace std;
 
vector <pair<int , int>> ans(1000);
int n , k , m , a;
 
class data
{
public:
    int votes;
    int number;
 
    data(){this->votes = 0; this->number = 0;}
};
class clasament
{
public:
    vector<data> v;
    clasament(int x)
    {
        this->v.resize(x);
        for(int i=0 ; i<x ; i++)
            this->v[i].number = i+1;
    }
 
    void update(int x)
    {
        int aux;
        for(int i=0 ; i<this->v.size() ; i++)
            if(this->v[i].number == x)
            {
                aux = i;
                this->v[i].votes++;
            }
        while(aux>=1 && this->v[aux].votes > this->v[aux-1].votes)
        {
            swap(this->v[aux].votes , v[aux-1].votes);
            swap(this->v[aux].number , v[aux-1].number);
            aux--;
        }
    }
    int position(int name)
    {
        for(int i=0 ; i<this->v.size() ; i++)
            if(this->v[i].number == name)
                return i;
        return 10000;
    }
    clasament& operator = (clasament a)
    {
        for(int i=0 ; i<a.v.size() ; i++)
        {
            this->v[i].votes = a.v[i].votes;
            this->v[i].number = a.v[i].number;
        }
        return *this;
    }
};
 
void canwin(int name , clasament cl)
{
    clasament b = cl;
    for(int i=0 ; i<m-a ; i++)
        b.update(name);
    if(b.position(name) < k)
        ans[name].first = 1;
}
void canlose(int name , clasament cl)
{
    int pos = cl.position(name);
    if(pos >= k || (cl.v[pos].votes == 0 && n>1))
    {
        ans[name].second = 1;
        return;
    }
    int nrv=0;
    for(int i=pos+1 ; i<=k ; i++)
        nrv += cl.v[pos].votes - cl.v[i].votes + 1;
    if(nrv <= m-a && n>k)
        ans[name].second = 1;
}
int main()
{
    cin >> n >> k >> m >> a;
    if(a == m)
    {
        clasament c(n);
        int x;
        for(int i=0 ; i<m ; i++)
        {
            cin >> x;
            c.update(x);
        }
        int ans[1000];
        for(int i=0 ; i<k ; i++)
        {
            if(c.v[i].votes > 0)
                ans[c.v[i].number] = 1;
            else ans[c.v[i].number] = 3;
        }
        for(int i=k ; i<n ; i++)
            ans[c.v[i].number] = 3;
        for(int i=1 ; i<=n ; i++)
            cout << ans[i] << " ";
        return 0;
    }
    clasament t(n);
    int x;
    for(int i=0 ; i<a ; i++)
    {
        cin >> x;
        t.update(x);
    }
    for(int i=1 ; i<=n ; i++)
        canwin(i , t);
    for(int i=1 ; i<=n ; i++)
        canlose(i , t);
    for(int i=1 ; i<=n ; i++)
    {
        if(ans[i].first && ans[i].second)
            cout << "2 ";
        else if(ans[i].first)
            cout << "1 ";
        else if(ans[i].second)
            cout << "3 ";
    }
}
