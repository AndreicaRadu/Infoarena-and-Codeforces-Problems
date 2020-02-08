#include <bits/stdc++.h>
using namespace std;
char diff3(char a , char b , char c)
{
    if(a == b)
        return c;
    if(b == c)
        return a;
    if(c == a)
        return b;
    return '!';
}
char same2(char a , char b , char c)
{
    if(a == b)
        return a;
    if(b == c)
        return b;
    if(c == a)
        return c;
    return '!';
}
int main()
{
    string x , y , z;
    cin >> x >> y >> z;
    vector <int> g;
    for(int i=0 ; i<x.length() ; i++)
        if(x[i] != y[i] || z[i] != y[i] ||x[i] != z[i])
            g.push_back(i);
    if(g.size() > 3)
    {
        cout << "Impossible";
        return 0;
    }
    if(g.size() <= 1)
    {
        cout << "Ambiguous";
        return 0;
    }
 
    set <string> ok;
    if(g.size() == 2)
        for (int j=0 ; j<3 ; j++)
            for (int l=0 ; l<3 ; l++)
            {
                string h;
                if (j == 0) h += x[g[0]];
                if (j == 1) h += y[g[0]];
                if (j == 2) h += z[g[0]];
                if (l == 0) h += x[g[1]];
                if (l == 1) h += y[g[1]];
                if (l == 2) h += z[g[1]];
                int m1 = 0, m2 = 0, m3 = 0;
                if (h[0] != x[g[0]]) m1++;
                if (h[1] != x[g[1]]) m1++;
                if (h[0] != y[g[0]]) m2++;
                if (h[1] != y[g[1]]) m2++;
                if (h[0] != z[g[0]]) m3++;
                if (h[1] != z[g[1]]) m3++;
                if (m1 < 2 && m2 < 2 && m3 < 2)
                    ok.insert(h);
            }
 
    if(g.size() == 3)
        for (int j=0 ; j<3 ; j++)
            for (int l=0 ; l<3 ; l++)
                for (int i=0 ; i<3 ; i++)
                {
                    string h;
                    if (j == 0) h += x[g[0]];
                    if (j == 1) h += y[g[0]];
                    if (j == 2) h += z[g[0]];
                    if (l == 0) h += x[g[1]];
                    if (l == 1) h += y[g[1]];
                    if (l == 2) h += z[g[1]];
                    if (i == 0) h += x[g[2]];
                    if (i == 1) h += y[g[2]];
                    if (i == 2) h += z[g[2]];
                    int m1 = 0, m2 = 0, m3 = 0;
                    if (h[0] != x[g[0]]) m1++;
                    if (h[1] != x[g[1]]) m1++;
                    if (h[2] != x[g[2]]) m1++;
                    if (h[0] != y[g[0]]) m2++;
                    if (h[1] != y[g[1]]) m2++;
                    if (h[2] != y[g[2]]) m2++;
                    if (h[0] != z[g[0]]) m3++;
                    if (h[1] != z[g[1]]) m3++;
                    if (h[2] != z[g[2]]) m3++;
                    //cout << h << " " << m1 << " " << m2 <<" "<< m3<<" \n";
                    if ((m1 < 2) && (m2 < 2) && (m3 < 2))
                        ok.insert(h);
                }
    if(ok.empty())
    {
        cout << "Impossible";
        return 0;
    }
    if(ok.size() > 1)
    {
        cout << "Ambiguous";
        return 0;
    }
    if(ok.size() == 1 && g.size() == 2)
    {
        auto e = ok.begin();
        string h = *e;
        x[g[0]] = h[0];
        x[g[1]] = h[1];
        cout << x;
    }
    if(ok.size() == 1 && g.size() == 3)
    {
        auto e = ok.begin();
        string h = *e;
        x[g[0]] = h[0];
        x[g[1]] = h[1];
        x[g[2]] = h[2];
        cout << x;
    }
}
