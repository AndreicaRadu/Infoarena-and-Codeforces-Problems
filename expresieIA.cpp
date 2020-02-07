#include <fstream>
using namespace std;
ifstream fin("expresie.in");
ofstream fout("expresie.out");
 
int main()
{
    long long n , a[1010] , sum=0 , ans=0;
    fin >> n;
    for(int i=0 ; i<n ; i++)
    {
        fin >> a[i];
        sum += a[i];
    }
    for(int i=1 ; i<n ; i++)
        for(int j=i+1 ; j<n ; j++)
        {
            long long k;
            if(i == j-1)
                k = sum - a[i-1] - a[i] - a[i+1] + a[i-1] * a[i] * a[i+1];
            else
                k = sum - a[i-1] - a[i] - a[j-1] - a[j] + a[i-1] * a[i] + a[j-1] * a[j];
            if(k > ans)
                ans = k;
        }
    fout << ans;
    return 0;
}
