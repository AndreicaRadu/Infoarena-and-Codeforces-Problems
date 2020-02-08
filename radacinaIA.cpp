#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("radacina.in"); ofstream fout("radacina.out");
 
int n;
vector <double> a;
double polinom(double x)
{
    double ans = a[n];
    for(int i=n-1 ; i>=0 ; i--)
    {
        ans *= x;
        ans += a[i];
    }
    return ans;
}
 
int main()
{
    fin >> n;
    for(int i=0 ; i<=n ; i++)
    {
        double j;
        fin >> j;
        a.push_back(j);
    }
    double left = -20 , right = 20;
    while(right - left > 0.000001)
    {
        double mid = (left + right)/2 , x = polinom(left) , y = polinom(mid);
        if((x<0 && y<0) || (x>0 && y>0))
            left = mid;
        else right = mid;
    }
    fout << left;
}
