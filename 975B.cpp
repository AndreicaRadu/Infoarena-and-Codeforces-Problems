#include <iostream>
#include <vector>
using namespace std;
 
long long mancala(vector <long long>  v, int k)
{
    long long a = v[k] , ans=0;
    v[k] = 0;
    for(int i=k+1 ; i<k+a%14+1 ; i++)
        v[i%14]++;
    for(int i=0 ; i<14 ; i++)
        v[i] += a/14;
    for(int i=0 ; i<14 ; i++)
        if(v[i]%2 == 0)
            ans += v[i];
    return ans;
}
 
int main()
{
    vector <long long> v(14);
    long long max = 0;
    for(int i=0 ; i<14 ; i++)
        cin >> v[i];
    for(int i=0 ; i<14 ; i++)
        if(v[i])
        {
            long long k = mancala(v , i);
            if(k > max)
                max = k;
        }
    cout << max;
}
