#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("fractal.in"); ofstream fout("fractal.out");
 
int f(int n , int a , int b)
{
    n--;
    if(n == 0)
    {
        if(a == 1 && b == 1) return 0;
        if(a == 2 && b == 1) return 1;
        if(a == 2 && b == 2) return 2;
        if(a == 1 && b == 2) return 3;
    }
    int m = 1 << n;
    if(a <= m && b <= m)
        return f(n , b , a);
    if(a <= m && b > m)
         return 3*m*m + f(n , 2*m-b+1 , m-a+1);
    if(a > m && b <= m)
        return m*m + f(n , a-m , b);
    if(a > m && b > m)
        return 2*m*m + f(n , a-m , b-m);
}
 
int main()
{
    int n;
    fin >> n;
    int a, b;
    fin >> a >> b;
    fout << f(n , b , a) << "\n";
}
