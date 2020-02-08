#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("text3.in");
ofstream fout("text3.out");
int n=1;
vector <string> str;
vector <pair <char , char>> v(20020);
int dist[20020] , dp[26] , pre[20020];
int main()
{
    string s;
    str.push_back("1111111");
    while(fin >> s)
    {
        str.push_back(s);
        v[n].first = s[0];
        v[n].second = s.back();
        n++;
    }
    n--;
    //cout << str[0];
    fout << n << "\n";
    v.resize(n+1);
    for(int i=1 ; i<=n ; i++)
        dist[i] = 1;
    for(int i=1 ; i<=n ; i++)
    {
        dist[i] = dist[dp[(int)v[i].first-97]] + 1;
        pre[i] = dp[(int)v[i].first-97];
        if(dist[i] > dist[dp[(int)v[i].second-97]])
            dp[(int)v[i].second-97] = i;
    }
    int last = 0;
    for(int i=1 ; i<=n ; i++)
        if(dist[i] > dist[last])
            last = i;
    //best--;
    stack <int> cuv;
    cuv.push(last);
    int best=1;
    while(pre[cuv.top()] != 0)
    {
        cuv.push(pre[cuv.top()]);
        best++;
    }
    fout << n - best << "\n";
    while(!cuv.empty())
    {
        fout << str[cuv.top()] << "\n";
        cuv.pop();
    }
}
