#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("z.in"); ofstream fout("z.out");
 
int f(int n , int a , int b)
{
    if(n == 0) return 1;
    n--;
    int m = 1 << n;
    if(a <= m && b <= m)
        return f(n , a , b);
    if(a <= m && b > m)
        return m*m + f(n , a , b-m);
    if(a > m && b <= m)
        return 2*m*m + f(n , a-m , b);
    if(a > m && b > m)
        return 3*m*m + f(n , a-m , b-m);
}
 
int main()
{
    int n , q;
    fin >> n >> q;
    for(int i=0 ; i<q ; i++)
    {
        int a, b;
        fin >> a >> b;
        fout << f(n, a, b) << "\n";
    }
}
