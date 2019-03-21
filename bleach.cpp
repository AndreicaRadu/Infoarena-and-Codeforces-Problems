#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
ifstream fin("bleach.in");ofstream fout("bleach.out");
int v[1000010];
int main()
{
    int N,K,i,t,a,j=0;
    long long s=0,pow;
    fin>>N>>K;
    priority_queue <int, vector<int>, greater<int> > heap;
    for(i=1;i<=K+1;i++) {fin>>a; heap.push(a);}
    for(i=K+2;i<=N+K+1;i++)
    {
        //s=s+k;
        //if(s<k) {s=s-p+k; p=k;}
        j++;
        v[j]=heap.top();
        heap.pop();
        if(i<=N)
        {
            fin>>t;
            heap.push(t);
        }
    }
    s=v[1];pow=v[1];
    for(i=1;i<=j;i++)
    {
        if(s>=v[i]) s=s+v[i];
        else
        {
            t=pow;
            pow=v[i]-(s-pow);
            s=s-t+pow+v[i];
        }
    }
    fout<<pow;
}
