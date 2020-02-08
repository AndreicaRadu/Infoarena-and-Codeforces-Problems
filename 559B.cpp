#include <bits/stdc++.h>
using namespace std;
 
void mina(string& s)
{
    if (s.size()%2 == 1)
        return;
    string x , y;
    for(int i=0 ; i<s.length()/2 ; i++)
        x += s[i];
    for(int i=s.length()/2 ; i<s.length() ; i++)
        y += s[i];
    mina(x);
    mina(y);
    if(x > y)
        s = y + x;
    else
        s = x + y;
}
 
int main()
{
    string a , b;
    cin >> a >> b;
    mina(a); mina(b);
    if (a == b)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
