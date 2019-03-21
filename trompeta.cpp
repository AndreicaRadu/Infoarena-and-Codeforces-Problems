#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
ifstream fin("trompeta.in");
ofstream fout("trompeta.out");
char n[5000000],m[5000000];
int main()
{
    int N,M,j,i,a,topn,topm;
    fin>>N>>M;fin>>n; m[0]=n[0]; topm=1;
    for(i=1;i<N;i++){
        if(M-topm>=N-i) {a=i;break;}
        while(M-topm<N-i&&n[i]>m[topm-1]&&topm>0) topm--;
        m[topm]=n[i];
        topm++;
    }
    for(i=topm;i<M;i++) {m[i]=n[a]; a++;}
    for(i=0;i<M;i++) fout<<m[i];
}
