#include <fstream>
using namespace std;
ifstream fin("maxsubsum.in"); ofstream fout("maxsubsum.out");
 
int main()
{
    int na, nb;
    long long s1[100010], a[100010], b[100010], s2[100010], ans;
    fin >> na >> nb;
    ans = -1000000000000;
    for (int i=1 ; i<=na ; i++)     //a[i] suma pana la al i-lea
    {
        s1[i] = -1000000000000;
        fin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i=1 ; i<=nb ; i++)
    {
        fin >> b[i];
        s2[i] = -1000000000000;
        b[i] += b[i - 1];
    }
    for (int i=1 ; i<=na ; i++)        //s1[i] cea mai mare suma pana la al i-lea din primul sir
        for (int j=i ; j<=na ; j++)
            s1[i] = max(s1[i], a[j] - a[j - i]);
 
    for (int i=1 ; i<=nb ; i++)
        for (int j=i ; j<=nb ; j++)
            s2[i] = max(s2[i] , b[j] - b[j - i]);
 
    for (int i=1 ; i<=na ; i++)
        for (int j=1 ; j<=nb ; j++)
            ans = max(ans , s1[i] * j + s2[j] * i);
    fout << ans;
    return 0;
}
