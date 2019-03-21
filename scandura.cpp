#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
ifstream fin("scandura.in"); ofstream fout("scandura.out");
queue<long long>v;queue<long long>u;

int main()
{
    long long N,M,a,i,sum=0,p,k;
    fin>>N>>M; k=N;
    if(M>2) while(N%(M-1)!=1) {N++; v.push(0);}
    for(i=1;i<=k;i++) {fin>>a; v.push(a);}
    a=0;
    while(!v.empty()||!u.empty())                            //N=q*(M-1)+1
    {
        for(i=1;i<=M;i++)
        {
            if(!v.empty()&& !u.empty())
            {
                if(v.front()<=u.front()) {a=a+v.front(); v.pop();}
                else if(v.front()>u.front()) {a=a+u.front(); u.pop();}
            }
            else if(!u.empty()) {a=a+u.front(); u.pop();}
            else if(!v.empty()) {a=a+v.front(); v.pop();}
        }
        sum+=a;
        if(!v.empty()|| !u.empty()) u.push(a);
        a=0;
    }
    fout<<sum;
}
