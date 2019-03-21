#include <fstream>
using namespace std;
long long put(long long p,long long b)
{
    if(p==0) return 1;
    if(b==1) return p%1000000007;
    if(b%2==0){
        return put(p*p%1000000007,b/2)%1000000007;
    }
    if(b%2==1){
        return (put(p*p%1000000007,(b-1)/2)*p)%1000000007;
    }
}
int main()
{
    ifstream fin("frumoasa.in");ofstream fout("frumoasa.out");
    long long N,P,a,i;
    fin>>N;fin>>P;
    if(P<=26){
    a=1;
    for(i=26;i>26-P;i--)
    {
        a=(a*i)%1000000007;
    }
    a=(put(26-P,N-P)*a)%1000000007;
    fout<<a; }
    else fout<<0;
    return 0;
}
