#include <iostream>
#include <fstream>
using namespace std;

long long put(long long N,long long P)
{
    if(N==0) return 1;
    if(P==1) return N%1999999973;
    if(P%2==0){
        return put(N*N%1999999973,P/2)%1999999973;
    }
    if(P%2==1){
        return put(N*N%1999999973,(P-1)/2)*N%1999999973;
    }
}
int main()
{
    ifstream fin("lgput.in");ofstream fout("lgput.out");
    int N,P;
    fin>>N>>P;
    fout<<put(N,P);
    return 0;
}
