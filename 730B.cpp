#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n == 1)
        {
            cout << "! " << 1 << " " << 1 <<"\n";
            continue;
        }
        vector<int> m, M;
        for (int i = 1; i < n; i += 2)
        {
            printf("? %d %d\n", i , i+1);
            fflush(stdout);
            char c; cin >> c;
            if(c == '>')
            {
                m.push_back(i+1);
                M.push_back(i);
            }
            else
            {
                M.push_back(i+1);
                m.push_back(i);
            }
        }
        int a=m[0];
        for(int i=1 ; i<m.size() ; i++)
        {
            printf("? %d %d\n", a , m[i]);
            fflush(stdout);
            char c; cin >> c;
            if(c == '>')
                a = m[i];
        }
        int b=M[0];
        for(int i=1 ; i<M.size() ; i++)
        {
            printf("? %d %d\n", b , M[i]);
            fflush(stdout);
            char c; cin >> c;
            if(c == '<')
                b = M[i];
        }
        if(n%2 == 0) cout << "! " << a << " " << b <<"\n";
        else
        {
            printf("? %d %d\n", a , n);
            fflush(stdout); char c; cin >> c;
            if(c == '>') a = n;
            printf("? %d %d\n", b , n);
            fflush(stdout); cin >> c;
            if(c == '<') b = n;
 
            cout << "! " << a << " " << b <<"\n";
        }
    }
    return 0;
}
